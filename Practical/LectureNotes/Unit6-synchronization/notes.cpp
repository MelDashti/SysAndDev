#include <iostream>
#include <thread>
#include <mutex>
#include <queue>

using namespace std;

queue<int> que;
mutex mtx; // mutex mtx: Declares a mutex for protecting the critical sections.
int n = 0;
const int Size = 10;

// nqueue function: Adds an element to the queue and updates the shared variable n.
void enqueue(int val) {
    // std::lock_guardstd::mutex lock(mtx): Automatically acquires the mutex lock when entering the critical section and releases it when the lock_guard goes out of scope.
    lock_guard<mutex> lock(mtx); // acquire lock
    if (n < Size) {
        que.push(val);
        n++;
        cout << "Enqueued" << val << ", n = " << n << endl;
    }
    // lock is automatically released when lock_guard goes out of scope.
}

//dequeue function: Removes an element from the queue and updates the shared variable n.
void dequeue() {
    lock_guard<mutex> lock(mtx);// acquire lock
    if (n > 0) {
        int val = que.front();
        que.pop();
        n--;
        cout << "Dequeued" << val << ", n = " << n << endl;
        // lock is automatically released
    }
}

//By using std::mutex and std::lock_guard, we ensure that the critical sections in enqueue and dequeue are executed by only one thread at a time, preventing race conditions.
int main() {
    thread t1(enqueue, 1); // create a thread to enqueue. 1 means the value to be enqueued
    thread t2(dequeue); // create a thread to dequeue
    t1.join(); // wait for t1 to finish
    t2.join(); // wait for t2 to finish
    return 0;
}