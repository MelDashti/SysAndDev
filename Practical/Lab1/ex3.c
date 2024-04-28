#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid; // pid_t is a data type defined in the library <sys/types.h> and is used to represent process IDs.
    int i;
    for (i = 1; i <= 3; i++) {
        switch (i) {
            case 1:
                fork();
                break; // What fork() does is that it creates a new process by duplicating the calling process.
                // The new process is called the child process, and the calling process is called the parent process.
                // The child process and the parent process run in separate memory spaces. At the time of fork() both the parent
                // and child processes start executing from the next instruction after the fork() call.
            case 2:
                pid = fork();
                if (pid != 0) system("echo case 2"); // system() is a library function that is used to execute a shell command.
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

// What this displays is the following:
// P1         |           C1
// P1 -> Pid != 0  case2   |     C1-> PID = 0   case2
// P1 -> Pid !=    P1C1      |      C1        |     C1C2
// case 3    |  case 3    |    case 3       |     case 3
//When the program starts, there's just one process, which we'll call P1.
//When i equals 1, fork() is called, creating a new process, which we'll call C1. Now there are two processes running: P1 and C1. Both continue executing from the point right after the fork() call.
//When i equals 2, both P1 and C1 reach another fork() call. P1 creates a new child process (let's call it P1C1), and C1 creates a new child process (let's call it C1C1). Now there are four processes running: P1, C1, P1C1, and C1C1.
//Still within case 2, the system("echo case 2") command is executed by all processes where pid != 0. In this case, P1 and C1 will execute this command because for them, pid is not equal to 0
//(it's the PID of their respective child processes). P1C1 and C1C1 won't execute this command because for them, pid is 0 (since they are the child processes and fork() returns 0 in the child process).