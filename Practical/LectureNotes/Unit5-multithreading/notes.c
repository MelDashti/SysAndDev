#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void revision() {

}


void *tF() {
    // Thread logic
    printf("Thread is running\n");
    pthread_exit(NULL);
}

int pthread_equal(pthread_t t1, pthread_t t2) {
    return t1 == t2;
}

int main() {
    // A thread is uniquely identified by its thread ID

    // remember that pthread id is only unique within a process.
    // So if you have multiple processes, you can have multiple threads with the same id.
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

    // pthread_create takes several arguments:
    // 1. pthread_t *tid: a pointer to a pthread_t variable that will be filled with the thread id of the new thread
    // 2. const pthread_attr_t *attr: a pointer to a pthread_attr_t structure that contains the attributes of the new thread
    // 3. void *(*start_routine)(void *): a pointer to the function that will be called by the new thread
    // 4. void *arg: a pointer to the argument that will be passed to the function that will be called by the new thread
    // pthread_create(pthread_t *tid, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
    pthread_t tid1;
    // the thread function should be a void function!
    int rc1 = pthread_create(&tid1, NULL, tF, NULL); // creates a thread and returns 0 if successful

    if (rc1) {
        printf("Error: return code from pthread_create() is %d\n", rc1);
        perror("pthread_create");
        exit(-1); // this will terminate the main thread
    }
}

void *thread_function(void *arg) {
    long tid = (long) arg;
    printf("Thread %ld is running\n", tid);
    pthread_exit((void *) tid);
}

int main2() {
    pthread_t threads[5];
    void *status;
    int rc;
    long t;

    for (t = 0; t < 5; t++) {
        rc = pthread_create(&threads[t], NULL, thread_function, (void *) t);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (t = 0; t < 5; t++) {
        rc = pthread_join(threads[t], &status);
        if (rc) {
            printf("Error: unable to join thread, %d\n", rc);
            exit(-1);
        }
        printf("Thread %ld joined with status %ld\n", t, (long) status);
    }

    pthread_exit(NULL);
}

