// Okay this is for better understanding barrie in posix threads
// We have 4 threads, and we want them to print messages in two phases. In the first phase, each thread will
// print "Phase 1 - Thread X". After all threads have printed this message, they will proceed to the second phase and print "Phase 2 - Thread X".
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4

pthread_barrier_t barrier;

void *thread_func(void *arg) {
    // we deference the argument to get the thread id
    int thread_id = *(int *) arg;

    // Phase 1
    printf("Phase 1 - Thread %d\n", thread_id);
    // Wait for all threads to complete phase 1
    pthread_barrier_wait(&barrier);
    // Phase 2
    printf("Phase 2 - Thread %d\n", thread_id);
    pthread_barrier_wait(&barrier);
}


int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize the barrier to wait for the 4 threads
    pthread_barrier_init(&barrier, NULL, NUM_THREADS);
    // Now we create the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func,
                       (void *) &thread_ids[i]);// the last parameter is the argument to the thread function
    }
    // wait for all threads to complete.
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the barrier
    pthread_barrier_destroy(&barrier);
    return 0;

}
