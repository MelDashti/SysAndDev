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

Semaphore semaphore;

void notify() {
    // even here we have to define the unique lock
    unique_lock<mutex> lock(semaphore.mtx);
    semaphore.count += 1;
    semaphore.cv.notify_one();
    // we don't need to unlock cuz mutex is automatically unlocked when lock goes out of scope
}

void sem_wait() {
    // the unique lock is declared here inside the sem_wait because
    // unique lock automatically locks and unlocks the mutex within a scope,
    // and each fun should have its own scope for locking mutex.
    unique_lock<mutex> u_lock(semaphore.mtx);
//    u_lock.lock(); this is not needed because in the previous line its locking by default.
    while (semaphore.count == 0) {
        semaphore.cv.wait(u_lock);
    }
    semaphore.count -= 1;
    //     // mutex is automatically unlocked when lock goes out of scope
}

int main() {

}