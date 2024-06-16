#include <iostream>
#include <semaphore>
#include <thread>
#include <condition_variable>
#include <vector>
#include <unistd.h> // This is for the sleep function.


using namespace std;

bool running = true;
int command = -1;
condition_variable cv;
mutex mx;
vector<int> vt;

void writer() {
    while (running) {
        this_thread::sleep_for(chrono::milliseconds(5000));
        unique_lock<mutex> w(mx);
        vt.emplace_back(rand() % 10 + 1);
        w.unlock();
    }
    return;
}

void ui() {
    int temp;
    while (running) {
        cout << "Command (0,1,2,3):  " << endl;
        cin >> temp;
        unique_lock<mutex> ui(mx);
        command = temp;
        if (temp == 0) {
            running = false;
        }
        cv.notify_one();
        ui.unlock();
    }
}

void worker() {
    while (running) {
        unique_lock<mutex> r(mx);
        while (vt.empty() || command == -1) {
            cv.wait(r);
            switch (command) {
                case 1:
                    cout << " ### Current elements: " << endl;
                    for (auto &e: vt)
                        cout << "id: " << e << endl;
                    break;
                case 2:
                    cout << " ### Last element: " <<
                         vt.back() << endl;
                    break;
                case 3:
                    cout << " ### All elements removed" << endl;
                    vt.clear();
                    break;
            }
            r.unlock();
        }
    }
}


int main(int) {
    cout << "START" << endl;
    thread t_wr(writer);
    thread t_u(ui);
    thread t_w(worker);
    t_wr.join();
    t_u.join();
    t_w.join();
    cout << "END" << endl;

}