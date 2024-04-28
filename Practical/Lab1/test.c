#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void dynamicMemAlloc(){
    // Here we see how to create a dynamic array in C.

    int *dynamicArray; // The reason this is a pointer is because we are going to allocate memory for the array dynamically.
    // int dynamicArray will not work because we are allocating memory dynamically and we need to store the address of the first byte of the memory allocated.
    // The memory allocated by malloc() or new will contain the actual values [0, 2, 4, 6, 8], not addresses.
    int size;

    printf("Enter the size of the array");
    scanf("%d", &size);


    // allocating memory for the dynamic array
    dynamicArray = (int *) malloc(
            size * sizeof(int)); // What happens here is that we are allocating memory for the array of size 'size'
    // and the size of each element is 'sizeof(int)'. What malloc does is that it allocates memory in the heap and returns the address of the first byte of the memory allocated.

    if (dynamicArray == NULL) {
        printf("Memory not allocated");
        exit(0);
    }
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = i * 2;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", dynamicArray[i]);
    }

}


int main() {
    int i, pid;
    setbuf(stdout,0);
    for (i=1; i<3; i++) {
        pid = fork();
        i++;
        if (pid!=0) {
            fork();
            printf("X");
        }
    }
    printf("X");
    return 1;
}


