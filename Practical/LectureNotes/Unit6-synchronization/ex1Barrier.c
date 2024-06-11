// Suppose barrier constructs do not exist
// re-implement them using only one semaphore and one mutex.
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

struct barrier {
    int counter;
    sem_t sem;
    pthread_mutex_t mutex;
};

struct barrier barrier_t;

void barrier_init(struct barrier *barrier, int num_threads) {
    barrier->counter = num_threads;
    sem_init(&barrier->sem, 0, 0);
    pthread_mutex_init(&barrier->mutex, NULL);
}

void barrier_wait(struct barrier *barrier) {
    pthread_mutex_lock(&barrier->mutex); // void barrier_wait(struct barrier *barrier) {
    pthread_mutex_lock(&barrier->mutex);
    barrier->counter--;
    if(barrier->counter == 0) { //  If the counter has reached 0, it means all threads have reached the barrier
        for(int i = 0; i < barrier->counter; i++) {
            sem_post(&barrier->sem); // so it posts to the semaphore once for each thread, then unlocks the mutex.
            // Remember every thread is waiting on the semaphore.
        }
    }
    pthread_mutex_unlock(&barrier->mutex);
    sem_wait(&barrier->sem);
}

void barrier_destroy(struct barrier *barrier) {
    sem_destroy(&barrier->sem);
    pthread_mutex_destroy(&barrier->mutex);
}


int main() {
    // Initialize the barrier
    int NUM_THREADS = 4;
    barrier_init(&barrier_t, NUM_THREADS);

    // Create and join threads, using thread_func as the thread function...

    // Destroy the barrier
    barrier_destroy(&barrier_t);

    return 0;
}

