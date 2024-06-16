#include <stdio.h>
#include <pthread.h>

// Define the number of threads
#define N 4

// Declare the barrier
pthread_barrier_t bar;

// Thread function
void *f(void *v) {
    int *v1 = (int *) v;
    int v2 = *v1;
    printf("Thread %d reached the barrier\n", v2);
    pthread_barrier_wait(&bar);
    printf("Thread %d passed the barrier\n", v2);
    pthread_exit(NULL);
}

int main() {
    pthread_t pthreads[N];
    int v[N];

    // Initialize the barrier with a count of N (number of threads)
    pthread_barrier_init(&bar, NULL, N);

    // Create threads
    for (int i = 0; i < N; i++) {
        v[i] = i;
        pthread_create(&pthreads[i], NULL, f, (void *) &v[i]);
    }

    // Join threads to ensure they all complete before the program exits
    for (int i = 0; i < N; i++) {
        pthread_join(pthreads[i], NULL);
    }

    // Destroy the barrier
    pthread_barrier_destroy(&bar);

    return 0;
}
