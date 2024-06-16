#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void waitRandomTime(int max) {
    sleep((int)(rand() % max) + 1);
}

void *taskA(void *arg) {
    waitRandomTime(10);
    printf("A\n");
    return NULL;
}

void *taskB(void *arg) {
    waitRandomTime(10);
    printf("B\n");
    return NULL;
}

void *taskD(void *arg) {
    waitRandomTime(10);
    printf("D\n");
    return NULL;
}

void *taskCF(void *arg) {
    waitRandomTime(10);
    printf("C\n");
    waitRandomTime(10);
    printf("F\n");
    return (void *)1;  // Return code
}

void *taskE(void *arg) {
    waitRandomTime(10);
    printf("E\n");
    return (void *)2;  // Return code
}

void *taskG(void *arg) {
    waitRandomTime(10);
    printf("G\n");
    return NULL;
}

int main(void) {
    pthread_t th_cf, th_e;
    void *retval;

    srand(getpid()); // Seed the random number generator
    // Task A
    pthread_t th_a;
    pthread_create(&th_a, NULL, taskA, NULL);
    pthread_join(th_a, NULL); // Wait for task A to complete

    // Task B
    pthread_t th_b;
    pthread_create(&th_b, NULL, taskB, NULL);
    pthread_join(th_b, NULL); // Wait for task B to complete

    // Task C and F
    pthread_create(&th_cf, NULL, taskCF, NULL);

    // Task D
    pthread_t th_d;
    pthread_create(&th_d, NULL, taskD, NULL);
    pthread_join(th_d, NULL);

    // Task E
    pthread_create(&th_e, NULL, taskE, NULL);

    // Wait for tasks E and CF to complete
    pthread_join(th_e, &retval);
    pthread_join(th_cf, &retval);

    // Task G
    pthread_t th_g;
    pthread_create(&th_g, NULL, taskG, NULL);
    pthread_join(th_g, NULL);

    return 0;
}