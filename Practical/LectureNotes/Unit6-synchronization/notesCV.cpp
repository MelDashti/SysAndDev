#include <iostream>
#include <semaphore>
#include <thread>
#include <mutex>
#include <condition_variable> // we have to import this library to use conditional variables

// In this we will see how to use conditional variables and what exactly they are
// Let's say we have two threads worker thread and notifier thread.
// The worker thread waits for a signal from the notifier thread to start working.

using namespace std;

mutex mtx; // a mutex to protect access to the shared variable ready
condition_variable cv; // A conditional variable to synchronize the two threads
bool ready = false; // A shared variable that indicates if the worker thread can proceed or not

void worker_thread() {
    // We have to use this in order to use cv.wait
    unique_lock<mutex> lock(mtx); // unique_lock is a type of lock that can be locked and unlocked multiple times
    cout << "Worker: waiting for the signal" << endl;
    cv.wait(lock, [] { return ready; }); // wait for the signal from the notifier thread.
    // What the above code means exactly is that the worker thread will wait for the signal from the notifier thread and will only continue when the ready variable is true
    // The variables passed in wait are the mutex and a lambda function that returns a boolean value.
    // The mutex is used to lock the thread and the lambda function is used to check if the condition is true or not. If the condition is true, the thread will continue, otherwise it will wait
    cout << "Worker received the signal" << endl;
}

void notifier() {
    this_thread::sleep_for(chrono::seconds(1)); // sleep for 1 second
    {
        lock_guard<mutex> lock(mtx); // lock the mutex
        // std::lock_guard: This is used in the notifier thread because it is simpler and provides a RAII-style m
        // mechanism to lock the mutex. It locks the mutex when the std::lock_guard is created and automatically unlocks it when the std::lock_guard goes out of scope.
        ready = true; // set the ready variable to true
        cout << "Notifier: sending signal" << endl;
    }
    cv.notify_one(); // notify the worker thread that the signal has been sent
//    The boolean ready is used as a condition to check whether the worker thread should proceed.
    // The cv.notify_one() function only wakes up the worker thread, but it doesn't guarantee that the condition the worker is waiting for is met.
}

int main() {
    thread t1(worker_thread); // create a worker thread
    thread t2(notifier); // create a notifier thread

    t1.join(); // wait for the worker thread to finish
    t2.join(); // wait for the notifier thread to finish

    return 0;
}