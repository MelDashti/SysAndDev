#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {
    char str[20];
    int n = atoi (argv[1]);

    setbuf (stdout, 0);
    if (n<=0) return (1);
    printf ("run with n=%d\n", n);
    if (fork()>0) {
        sprintf (str, "%d", n-1);
        printf ("exec\n");
        execlp (argv[0], argv[0], str, (char *) 0);
    } else {
        sprintf (str, "%s %d", argv[0], n-2);
        printf ("system\n");
        system (str);
    }
    wait((int *) 0);

    return (1);
}



int main0() {
    printf("Before system\n");
    system("ls -l");
    printf("After system\n");
    return 0;
}
//system("ls - l"): Executes the ls command in long format.
//Output: "Before system" is printed, followed by the output of ls -l, and then "After system" is printed.

// using execl
int main2() {
    printf("Before exec\n");
    execl("/bin/ls", "ls", "-l", (char *)NULL);
    printf("This will not be printed if exec is successful\n");
    return 0;
}
// execl("/bin/ls", "ls", "-l", (char *)NULL): Replaces the current process with the ls command, listing files in long format.
//Output: The current process is replaced by ls, so "Before exec" is printed, but "This will not be printed if exec is successful" is not.