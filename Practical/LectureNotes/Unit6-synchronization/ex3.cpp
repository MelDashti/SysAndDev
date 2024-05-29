#include <iostream>
#include <semaphore>
#include <thread>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
// we use priority queue to store the threads
// We want to store in our priority queue a pair of a thread and an integer.
// The integer will be the priority of the thread.
// We will use the priority queue to store the threads in the order of their priority.

// A priority queue is a special type of queue in which each element is associated with a priority and is served according to its priority. If elements with the same priority occur, they are served according to their ordering in the queue.

const int TIME = 3;

// In c++20 semaphores are neither copyable nor movable. We need to carefully use
// dynamic memory allocation .
map<int, unique_ptr<binary_semaphore>> my_sems; // unique_ptr is a smart pointer that owns and manages another object through a pointer and disposes of that object when the unique_ptr goes out of scope.
mutex m;

static void worker(int i, int priority) {
    m.lock(); // we lock the mutext so that we can print the message in a single line without any interruption
    cout << "Locking thread" << i << " with priority " << priority << endl;
    m.unlock();
    my_sems.insert({priority, make_unique<binary_semaphore>(0)});// we add the semaphore with the priority to the map
    (*my_sems[priority]).acquire(); // we acquire the semaphore so that the thread is blocked and is waiting for the release
    m.lock(); // we lock the mutext so that we can print the message in a single line without any interruption
    cout << " Unlocked thread" << i << " with priority " << priority
         << endl; // if this line of code runs it means the semaphore has been released
    m.unlock();
}


int main() {
    int i, priority, numOfthreads = 5;
    vector<thread> pool; // we create a vector of threads.
    for (i = 0; i < numOfthreads; i++) {
        priority = (i + 1) * 10; // here we set the priority of the thread
        // We add the thread to the pool. The thread will be created by the lambda function.
        pool.emplace_back(
                [i, priority] { worker(i, priority); }); // this will create a new thread and add it to the pool
    }
    this_thread::sleep_for(chrono::seconds(TIME));
    i = 0;
//    n C++, std::map automatically sorts its keys in ascending order. So, when you iterate over my_sems, you're effectively iterating over the semaphores in order of ascending priority. Since a lower priority value indicates a higher priority level, this means you're releasing the threads in order of highest to lowest priority.
    for (const auto &t: my_sems) { // here we iterate over the map of semaphores
        m.lock();
        // here we print the message that the thread is being unlocked
        cout << "Unlocking thread " << i << " with priority " << t.first << endl;
        m.unlock();
        (*t.second).release();
    }
    for (i = 0; i < numOfthreads; i++) {
        pool[i].join();
    }
    cout << "Main exists." << endl;
    return (1);

}