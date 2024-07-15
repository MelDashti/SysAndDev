#include <iostream>
#include <future>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex m1, m2, m3;
condition_variable cv1, cv2, cv3;
bool ready1, ready2, ready3;

void f1(shared_ptr<promise<string>> p, shared_ptr<future<string>> f) {
    bool first = true;
    string a;
    while (a != "exit") {
        unique_lock<mutex> lock(m3);
        while (!ready3)
            cv3.wait(lock);
        if (!first) {
            p.reset(new promise<string>());
            auto ft = p->get_future();
            f.reset(new future<string>(std::move(ft)));
        }
        ready3 = false;
        ready1 = true;
        cv1.notify_one();
        cout << "Enter a string >";
        cin >> a;
        p->set_value(a);
        first = false;
    }
}

void f2(shared_ptr<promise<string>> p, shared_ptr<future<string>> f, shared_ptr<future<string>> f2) {
    bool first = true;
    string b;
    while (b != "EXIT") {
        unique_lock<mutex> lock(m1);
        while (!ready1)
            cv1.wait(lock);
        if (!first) {
            b.clear();
            p.reset(new promise<string>());
            auto ft = p->get_future();
            f2.reset(new future<string>(std::move(ft)));
        }
        ready1 = false;
        ready2 = true;
        cv2.notify_one();
        for (char c: f->get())
            b += static_cast<char>(toupper(c));
        p->set_value(b);
        first = false;
    }
}

void f3(shared_ptr<future<string>> f) {
    string a;
    while (a != "EXIT") {
        unique_lock<mutex> lock(m2);
        while (!ready2)
            cv2.wait(lock);
        a = f->get();
        cout << a << endl;
        ready2 = false;
        ready3 = true;
        cv3.notify_one();
    }
}

int main() {
    auto p1 = make_shared<promise<string>>();
    auto p2 = make_shared<promise<string>>();
    auto ft1 = p1->get_future();
    auto ft2 = p2->get_future();
    auto fut1 = make_shared<future<string>>(std::move(ft1));
    auto fut2 = make_shared<future<string>>(std::move(ft2));
    ready1 = false;
    ready2 = false;
    ready3 = true;
    auto T1 = async(launch::async, f1, std::move(p1), std::move(fut1));
    auto T2 = async(launch::async, f2, std::move(p2), std::move(fut1), std::move(fut2));
    auto T3 = async(launch::async, f3, std::move(fut2));
    T1.get();
    T2.get();
    T3.get();
    return 0;
}