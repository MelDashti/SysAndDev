#include <iostream>
#include <mutex>
#include <vector>
#include <thread>
#include <shared_mutex>

using namespace std;

mutex m;
recursive_mutex rm;


// here we see how using RAII can help us avoiding errors in the code when dealing with mutexes
void RAIIWrapper() {
    lock_guard<mutex> lg(m); // mutex is locked when lg is created and unlocked when lg goes out of scope
    unique_lock<mutex> ul(m); // mutex is locked when ul is created and unlocked when ul goes out of scope
    // unique_lock is used when we want to lock and unlock the mutex multiple times
}

void RAIIExample() {
    unique_lock l{m};

}


void f2() {
    rm.lock(); // lock the recursive mutex
    cout << "bar \n" << endl; // f2 must also lock and unlock IO because can be called directly (not through f1)
    rm.unlock(); // unlock the recursive mutex
}

void f1() {
    rm.lock(); // lock the recursive mutex
    cout << "f1" << endl;
    f2(); // call f2 which locks the same mutex
    rm.unlock(); // unlock the recursive mutex

}

void safe_print(int i) {
    m.lock();
    std::cout << i;
    m.unlock();
}

int main() {
    std::vector<std::thread> threadPool;
    for (int i = 1; i <= 9; ++i) {
        threadPool.emplace_back(
                [i] {
                    safe_print(i);
                }); // emplace basically creates a new thread and adds it to the vector. It creates the thread by itself so we don't have to define it
        // if instead of emplace_back we use push_back, we would have to define the thread and then add it to the vector
//                threadPool.push_back(std::thread([i] { safe_print(i); });
    }
    for (auto &t: threadPool) {
        t.join(); // wait for the thread to finish
    }

    int value = 0;
    std::shared_mutex sm;
    vector<thread> tv;
    for (int i = 0; i < 5; i++) {
        tv.emplace_back(
                [&] { // [&] means that the lambda function captures all variables by reference. so any variable if changed in the lambda function will be changed in the main function as well
                    sm.lock_shared();
//            value++; // error because we are trying to write to value while it is shared_locked, other threads can read value but not write to it
                    cout << value << endl; // no error because we are only reading value
                    sm.unlock_shared();
                });
    }
    for (int i = 0; i < 5; i++) {
        tv.emplace_back([&] {
            sm.lock();
            value++; // no error because we are writing to value while it is locked
            sm.unlock();
        });
    }

    return 0;

} // The digits 1 to 9 are printed to the console. The order of the digits is not guaranteed because the threads run concurrently, but the use of the mutex ensures that each digit is printed atomically (without interleaving).
