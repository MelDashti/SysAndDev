#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sp, sm, ss, sl;

void *tP(void *pVoid) {
    int n = *(int *) pVoid;
    int np = 0;
    while (1) {
        sem_wait(&sp);
        printf("+");
        np++;
        if (np < n) {
            sem_post(&sp);
        } else {
            np = 0;
            sem_post(&sm);
        }
    }
}

void *tM(void *pVoid) {
    int n = *(int *) pVoid;
    int nm = 0;
    while (1) {
        sem_wait(&sm);
        printf("-");
        nm++;
        if (nm < n) {
            sem_post(&sm);
        } else {
            nm = 0;
            sem_post(&ss);
        }
    }

}

void *tS(void *pVoid) {
    int n = *(int *) pVoid;
    int ns = 0;
    while (1) {
        sem_wait(&ss);
        printf("*");
        ns++;
        if (ns < n) {
            sem_post(&ss);
        } else {
            ns = 0;
            sem_post(&sl);
        }
    }

}

void *tN(void *pVoid) {
    int nl = 0;
    while (1) {
        sem_wait(&sl);
        nl++;
        printf("\n");
        sem_post(&sp);
    }

}

int main(int argc, char **argv) {
    int n;
    if (argc != 2) {// Check if the number of arguments is correct.
        // if not, print the usage of the program and exit.
        printf("Usage: %s <number>\n", argv[0]);
        exit(1);
    }
    n = atoi(argv[1]); // Convert the argument to an integer.

    // Initialize the semaphores
    sem_init(&sp, 0, 1);
    sem_init(&sm, 0, 0);
    sem_init(&ss, 0, 0);
    sem_init(&sl, 0, 0);

    // Create the threads
    pthread_t tp, tm, ts, tn;
    pthread_create(&tp, NULL, tP, NULL);
    pthread_create(&tm, NULL, tM, NULL);
    pthread_create(&ts, NULL, tS, NULL);
    pthread_create(&tn, NULL, tN, NULL);

    // Wait for the threads to finish
    pthread_join(tp, NULL);
    pthread_join(tm, NULL);
    pthread_join(ts, NULL);
    pthread_join(tn, NULL);

}