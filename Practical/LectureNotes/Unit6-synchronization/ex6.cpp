#include <iostream>
#include <semaphore>
#include <thread>
#include <future>

using namespace std;

bool f_and(bool in1, bool in2) {
    bool out = in1 & in2;
    cout << in1 << " AND " << in2 << " = " << out << endl;
    return out;
}

bool f_or(bool in1, bool in2) {
    bool out = in1 || in2;
    cout << in1 << "OR" << in2 << "=" << out << endl;
}

int main() {
    bool in1 = false;
    bool in2 = true;
    bool in3 = false;
    bool in4 = true;
    bool in5 = true;
    bool in6 = true;
    bool in7 = true;
    bool in8 = false;

    // first four gates
    future<bool> s1f = async(::launch::async, f_or, in1, in2);
    future<bool> s2f = async(::launch::async, f_or, in3, in4);
    future<bool> s3f = async(::launch::async, f_or, in5, in6);
    future<bool> s4f = async(::launch::async, f_or, in7, in8);

    // 2nd phase gates
    future<bool> s5f = async(::launch::async, f_and, s1f.get(), s2f.get());
    future<bool> s6f = async(::launch::async, f_and, s3f.get(), s4f.get());

    // 3rd phase
    future<bool> s7f = async(::launch::async, f_or, s5f.get(), s6f.get());

    cout << s7f.get();

}