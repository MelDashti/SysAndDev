#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// Fork() concept
// The fork() system call is fundamental in Unix-like operating systems.
// fork creates a new process by duplicating the calling process. The new process is called the child process, and the calling process is called the parent process.



int main() {
    pid_t pid;

    pid = fork();
    if (pid < 0) {
        // fork failed
        perror("fork failed");
    } else if (pid == 0) {
        printf("I am the child process. PID: %d \n", getpid());
    } else {
        printf("I am the parent process. PID: %d, Child PID: %d\n", getpid());
    }

    // multiple fork() calls
    pid_t pid1, pid2;
    pid1 = fork();
    if(pid1==0){
        // child process
        printf("I am the child process. PID: %d \n", getpid());
    }
    else{
        // parent process
        pid2 = fork();
        // 2nd fork
        if(pid2==0){
            // second child process
            printf("second child process. PID: %d \n", getpid());
        }else{
            // parent process
            printf("I am the parent process. PID: %d, Child PID: %d\n", getpid(), pid1);
        }
    }


    return 0;
}