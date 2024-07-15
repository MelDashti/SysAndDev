// CV example in c with posix threads
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex; // Mutex (pthread_mutex_t mtx): A mutex to protect access to the shared variable ready. It ensures that only one thread can access the shared variable at a time.
pthread_cond_t cv; // this is the conditional variable in c. A condition variable to synchronize the worker and notifier threads. It allows the worker thread to wait until the notifier thread signals it.
int ready = 0; //  A shared integer variable that indicates whether the worker thread can proceed. Initially set to 0 (false).


void *worker(void *arg) {
    pthread_mutex_lock(
            &mutex); // This ensures that no other thread can modify the ready variable while the worker thread is checking it.
    printf("Worker: waiting for the signal");
    while (!ready) {// The worker thread enters a while loop that checks the ready variable. If ready is 0 (false), the thread calls pthread_cond_wait(&cv, &mtx);
        pthread_cond_wait(&cv, &mutex); // this is the wait function for the conditional variable
        // Temporarily unlocks the mutex., Puts the thread in a waiting state.
        // Re locks the mutex when the thread is signaled and awoken.
    } //
    // once ready is 1, exits while loop and prints the following message.
    printf("Worker: received the signal and proceeding\n");
    pthread_mutex_unlock(
            &mutex); // the worker thread unlocks the mutex after it has finished using the shared variable.
    return NULL;
}

void *notifier(void *arg) {
    sleep(1);
    pthread_mutex_lock(&mutex);
    ready = 1;
    printf("Notifier: ready to notify\n");
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cv); // used to notify threads that a condition has been satisfied.
    // this is the signal function for the conditional variable
    // The notifier thread unlocks the mutex using pthread_mutex_unlock(&mtx); and calls pthread_cond_signal(&cv); to wake up the worker thread.
    return NULL;
}

int main() {
    pthread_t t1, t2;
    // Alternate mutex and cv initialization. pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER; pthread_cond_t c = PTHREAD_COND_INITIALIZER;
    pthread_mutex_init(&mutex,
                       NULL); // the mutex and conditional variables are initialized using pthread_mutex_init() and pthread_cond_init(&cv, NULL).
    pthread_cond_init(&cv, NULL); // cv initialization.

    // two threads are created: one for the worker function and one for the notifier function.
    pthread_create(&t1, NULL, worker, NULL);
    pthread_create(&t2, NULL, notifier, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(
            &mutex); // the mutex and conditional variables are destroyed using pthread_mutex_destroy() and pthread_cond_destroy(&cv).
    pthread_cond_destroy(&cv);

}
// Understanding pthread_cond_wait:
// 1. Lock the Mutex:
//Before calling pthread_cond_wait, the thread must lock a mutex. This mutex is typically used to protect a shared
// resource or condition (like the ready variable in our example).
//2. Call pthread_cond_wait:
//When pthread_cond_wait is called, it atomically:
//Unlocks the Mutex: This is done to allow other threads to acquire the mutex and modify the shared resource or
// condition. The unlocking happens atomically with the thread being placed on the condition variable's wait queue.
// This atomic operation is crucial because it prevents a race condition between unlocking the mutex and entering the
// waiting state.
//Enters the Waiting State: The thread is placed into a waiting state where it will remain until it is specifically
// notified (via pthread_cond_signal or pthread_cond_broadcast), or until a spurious wakeup occurs.
//3. Woken Up:
//When the condition variable is signaled (using pthread_cond_signal or pthread_cond_broadcast), the waiting thread is awakened. However, before it can proceed with its execution, it must re-acquire the mutex it released when it entered pthread_cond_wait. This re-acquisition is automatic and handled internally by pthread_cond_wait.
//4. Mutex is Re-locked:
//The thread will not exit the pthread_cond_wait function until it successfully re-acquires the mutex.
// This ensures that when the thread resumes execution after waiting, it holds the mutex, just as it did when
// it initially called pthread_cond_wait.
//5. Proceed with Execution:
//Once the mutex is re-acquired, the thread can safely check the condition and proceed with its execution,
// knowing that it has exclusive access to the shared resources protected by the mutex.


//#include <stdio.h>
//#include <semaphore.h>
//#include <pthread.h>
//#include <unistd.h>
//
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // initializes a mutex
//pthread_cond_t cv = PTHREAD_COND_INITIALIZER; // initializes a conditional variable
//int ready = 0; // A flag to indicate when the signal is ready!
//
//void *waitForTheSignal() {
//    pthread_mutex_lock(&mutex); // lock the mutex
//    while (!ready) {
//        pthread_cond_wait(&cv, &mutex); // wait for the signal
//    }
//    printf("Thread 1 received the signal\n");
//    pthread_mutex_unlock(&mutex); // unlock the mutex
//    return NULL;
//}
//
//void *sendTheSignal() {
//    sleep(1);// simulate some word
//    pthread_mutex_lock(&mutex); // lock the mutex
//    ready = 1;
//    printf("Thread 2 sent the signal\n");
//    pthread_cond_signal(&cv); // send the signal
//    pthread_mutex_unlock(&mutex); // unlock the mutex
//    return NULL;
//}
//
//int done = 0;
//
//void *child(void *arg) {
//    pthread_mutex_lock(&mutex);
//    done = 1;
//    pthread_cond_signal(&cv);
//    pthread_mutex_unlock(&mutex);
//    return NULL;
//}
//
//
//int main() {
//    pthread_t p;
//    pthread_create(&p, NULL, child, NULL);
//    pthread_mutex_lock(&mutex);
//    while (done == 0) {
//        pthread_cond_wait(&cv, &mutex);
//    }
//    pthread_mutex_unlock(&mutex);
//
//
//    //    pthread_t t1, t2;
////    pthread_create(&t1, NULL, waitForTheSignal, NULL);
////    pthread_create(&t2, NULL, sendTheSignal, NULL);
////    pthread_join(t1, NULL);
////    pthread_join(t2, NULL);
//
//}
