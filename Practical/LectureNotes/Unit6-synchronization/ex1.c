#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

pthread_mutex_t mutex;
sem_t sA, sB;
int counter;

void * tA(void *pVoid) {
    sem_wait(&sA);
    pthread_mutex_lock(&mutex);
    counter++;
    printf("A");
    if (counter >= 3) {
        sem_post(&sA);
        sem_post(&sB);
        sem_post(&sB);
        counter = 0;
        printf("\n");
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void * tB(void *n2) {
    int *n = (int *) n2;
    int n3 = *n;

    for (int i = 0; i < n3; i++) {
        sem_wait(&sB);
        pthread_mutex_lock(&mutex);
        counter++;
        printf("B");
        if (counter >= 3) {
            sem_post(&sA);
            sem_post(&sA);
            sem_post(&sB);
            counter = 0;
            printf("\n");
        }
        pthread_mutex_unlock(&mutex);

    }
}

int main() {
    int n1 = 1, n2 = 2;
    counter = 0;
    // we initialize the semaphores and mutex
    sem_init(&sA, 0, 1);
    sem_init(&sB, 0, 2);
    pthread_mutex_init(&mutex, nullptr);

    pthread_t ta;
    pthread_t tb;
    pthread_t tid;

    while (true) {
        pthread_create(&ta, NULL, tA, NULL);
        pthread_create(&tb, NULL, tB, &n2);
        pthread_join(ta, NULL);
        pthread_join(tb, NULL);
    }

}