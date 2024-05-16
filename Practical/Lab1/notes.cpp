#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid; // pid_t is a data type defined in the library <sys/types.h> and is used to represent process IDs.
    int i;
    for (i = 1; i <= 3; i++) {
        switch (i) {
            case 1:
//                fork();
                break; // What fork() does is that it creates a new process by duplicating the calling process.
                // The new process is called the child process, and the calling process is called the parent process.
                // The child process and the parent process run in separate memory spaces. At the time of fork() both the parent
                // and child processes start executing from the next instruction after the fork() call.
            case 2:
//                pid = fork();
                if (pid != 0) system("echo case 2");
                break; // Here we can see if the parent process or the child process is executing the code by checking the value of pid.
                // if pid is not equal to 0, then the parent process is executing the code, otherwise the child process is executing the code.
            case 3:
                execlp("echo", "myPgrm", "case 3", NULL);
                // exec is used to replace the current process with a new process. The new process is loaded into the current process's memory space.
                // execlp is being used here to replace the current process image with the echo command.
                // The arguments to echo are passed as seperate arguments to execlp.
                // "echo" is the command that is being executed, "myPgrm" is the name of the program, "case 3" is the argument to echo, and NULL is the end of the argument list.

                //
                break;
        }
        return (0);
    }}