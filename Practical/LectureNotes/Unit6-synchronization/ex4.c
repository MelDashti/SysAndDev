#include "stdio.h"
#include "pthread.h"
#include "stdlib.h"
#include "semaphore.h"
#include "unistd.h"

typedef struct best_s {
    int rank;
    long int id;
    int num_votes;
    pthread_mutex_t mutex;
} best_t;

best_t *best;
sem_t *sem;

int max_random(int max);


int main(int argc, char **argv) {
    pthread_t th;
    int i, j, k, pi; // the main function then creates N threads. Each thread is assigned with a rank and then started
    best = (best_t *) malloc(sizeof(best_t));
    best->rank = best->num_votes = 0;
    pthread_mutex_init(&best->mutex, NULL);
    sem = (sem_t *) malloc(sizeof(sem_t));
    sem_init(sem, 0, 0);
    

    pthread_exit(0);


}





