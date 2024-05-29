// A semaphore is different from a mutex in that it is not bound to a specific
// thread. This means that the acquire (wait) and release (signal) operations on
// a semaphore can be performed by different threads.
// Suppose C++20 does not exist yet
// Implement a C++ semaphore using a mutex and CV.
#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

struct Semaphore {
    int count;
    mutex mtx;
    condition_variable cv;
};

void notify() {

}

void sem_wait() {
    unique_lock<mutex> lock(m);
}

