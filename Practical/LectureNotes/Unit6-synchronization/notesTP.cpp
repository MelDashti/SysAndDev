// Thread Throttles And Pools
// Semaphore Throttles And Thread Pools are introduced to avoid over-subscription.
//

// Semaphore Throttles

// implementing a thread pool in c++

#include <iostream>
#include <semaphore>
#include <thread>
#include <condition_variable>
#include <vector>
#include <functional>
#include <queue>

using namespace std;


class ThreadPool {
public:
    void Start();

    void QueueJob(const function<void()> &job);

    void stop();

    void busy();

private:
    void ThreadLoop();

    // tells the threads to stop looking for jobs
    bool should_terminate = false;
    // prevents data races to the job queue
    mutex queue_mutex;
    // ALlows threads to wait on new jobs for termination
    condition_variable mutex_condition;
    vector<thread> threads;
    queue<function<void()>> job_queue;
};

