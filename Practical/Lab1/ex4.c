//Code analysis: fork, exec, system
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {
    int i;
    for (i=0; i<2; i++) {
        printf ("i=%d\n", i);
        if (fork())             // Call # 1
            fork ();              // Call # 2
        else
            system ("echo i=i");  // Call # 3
    }
    return (1);
}

// i = 0
//  P1      |       C1
// P1->fork()  |   C1  i = i
// P1   i = 1    |    P1C1    i=1   |  C1   i=1
// P1-> fork() |  P1C1->fork() |  C1->fork()
// P1     |  P1C2  |  P1C1C1  |  C1   |   C1C1
// P1->fork() |  P1C2->fork() |  P1C1C1  i=2  |  C1->fork() |  C1C1  i = 2