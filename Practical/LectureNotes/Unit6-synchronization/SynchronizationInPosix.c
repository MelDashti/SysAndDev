#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>


// Posix mutexes
void mutexDef() {
    // A mutex is represented by the pthread_mutex_t type. The following functions are used to work with mutexes:
    pthread_mutex_t mutex; //
    // before using the mutex, it must be initialized using pthread_mutex_init.
    // 0 is returned if the mutex is successfully initialized, otherwise an error number is returned.
    pthread_mutex_init(&mutex, NULL); // to set the mutex attributes to default, the second argument is NULL.

    // blocks the caller is the mutex is locked
    // acquire the lock if the mutex is unlocked
    pthread_mutex_lock(&mutex); // lock the mutex

    // if a mutex can't afford to be blocked, use trylock
    // returns 0 if the mutex is successfully locked, otherwise an error number is returned.
    pthread_mutex_trylock(&mutex); // try to lock the mutex

    // this function unlocks the mutex that was previously locked by the calling thread.
    pthread_mutex_unlock(&mutex); // unlock the mutex

    // this function destroys the mutex and releases any resources associated with it.
    // Used for dynamically allocated mutexes
    pthread_mutex_destroy(&mutex); // destroy the mutex
}

// example use a dynamically allocated mutex to protect a cs
void example() {
    pthread_mutex_t *mutex;
    mutex = (pthread_mutex_t *) malloc(sizeof mutex);
    pthread_mutex_lock(mutex);
    printf("critical section");
    pthread_mutex_unlock(mutex);
    pthread_mutex_destroy(mutex);
    free(mutex);
}


// Posix semaphores
// we create a function that will be called by the threads
void semaphoreDef() {
    sem_t sem;// sem_t is a type defined in semaphore.h
    // pshared: 0 for shared between threads, non-zero for shared between processes
    // value: initial value of the semaphore. unsigned int
    sem_init(&sem, 0,
             0);// sem_init initializes the semaphore sem. The second argument is a flag that specifies whether the semaphore is shared between processes (0 for shared, non-zero for private). The third argument is the initial value of the semaphore.
    // sem wait will decrement the value of the semaphore by 1 if the value is greater than 0. If the value is 0, the function will block until the value is greater than 0.
    sem_wait(&sem);// sem_wait decrements the value of the semaphore by 1.
    // Non-blocking version of sem_wait. It will return immediately with an error (-1) if the value of the semaphore is 0.
    sem_trywait(
            &sem); // sem_trywait decrements the value of the semaphore by 1 if the value is greater than 0. If the value is 0, the function returns immediately with an error.
    // sem_post increments the value of the semaphore by 1. ( unlocks the semaphore). If there are threads waiting on the semaphore, one of them will be unblocked.
    sem_post(&sem);
    sem_getvalue(&sem, 0);
    sem_destroy(&sem);
}

// here we take a look at static semaphores
void staticSemaphore() {
    sem_t sem;
    sem_init(&sem, 0, 0);
    sem_wait(&sem);
    sem_post(&sem);
    sem_destroy(&sem);
}

// Here we take a look at dynamic semaphores
void dynamicSemaphore() {
    sem_t *sem;
    sem = (sem_t *) malloc(sizeof(sem_t));
    sem_init(sem, 0, 0);
    sem_wait(sem);
    sem_post(sem);
    sem_destroy(sem);
    free(sem);
}

//


int main() {

    sem_t sem;
    sem_init(&sem, 0, 0); // initialize the semaphore with a value of 0. The semaphore is shared between threads.





}