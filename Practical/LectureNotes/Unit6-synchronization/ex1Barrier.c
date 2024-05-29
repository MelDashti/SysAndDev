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
} barrier_t;

void *wait() {
    barrier_t

}


int main() {

}

