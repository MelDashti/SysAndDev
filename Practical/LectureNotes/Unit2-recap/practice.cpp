#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {

    int fd;
    // opening the file for reading only
    ssize_t bytesRead;
    char buffer[BUFFER_SIZE];
    int i = 0;
    // declares an integer variable fd to store the file descriptor returned by open
    fd = open(
            "C:\\Users\\meela\\Desktop\\System And Device Programming\\Practical\\LectureNotes\\Unit2-recap\\test.txt",
            O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    // File operatio;ns
    while ((read(fd, buffer, 10))) {
        printf("%s", buffer);
    }
}