#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *tF() {
    // Thread logic
    printf("Thread is running\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t tid;
    int rc;
    rc = pthread_create(&tid, NULL, tF, NULL); // creates a thread and returns 0 if successful
    if (rc) {
        printf("Error: return code from pthread_create() is %d\n", rc);
        perror("pthread_create");
        exit(-1); // this will terminate the main thread
    }

    // Other main thread logic
    printf("Main thread is running\n");
    pthread_exit(NULL);
    // exit(0); // this will terminate the main thread
    // return 0; // this will terminate the main thread



}


