#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <ctype.h>

void waitRandomTime(int max) {
    sleep((int)(rand() % max) + 1);
}

static void *GET(void *arg) {
    char *c = (char *) arg;
    *c = fgetc(fg);
    return NULL;
}

static void *UPD(void *arg) {
    char *c = (char *) arg;
    *c = toupper(*c);
    return NULL;
}

static void *PRINT(void *arg) {
    char *c = (char *) arg;
    putchar(*c);
    return NULL;
}

FILE *fg;

int main(int argc, char **argv) {
    char next, this, last; // next, this, last characters
    int rc;
    pthread_t tGet, tUpd, tPrint;
    void *retv;

    if ((fg = fopen(argv[1], "r")) == NULL) {
        perror("Error fopen\n");
        exit(0);
    }

    this = ' ';
    last = ' ';
    next = ' ';

    while (next != EOF) {
        rc = pthread_create(&tGet, NULL, GET, &next);
        if (rc != 0) fprintf(stderr, "Error creating GET thread\n");

        rc = pthread_create(&tUpd, NULL, UPD, &this);
        if (rc != 0) fprintf(stderr, "Error creating UPD thread\n");

        rc = pthread_create(&tPrint, NULL, PRINT, &last);
        if (rc != 0) fprintf(stderr, "Error creating PRINT thread\n");

        rc = pthread_join(tGet, &retv);
        if (rc != 0) fprintf(stderr, "Error joining GET thread\n");

        rc = pthread_join(tUpd, &retv);
        if (rc != 0) fprintf(stderr, "Error joining UPD thread\n");

        rc = pthread_join(tPrint, &retv);
        if (rc != 0) fprintf(stderr, "Error joining PRINT thread\n");

        last = this;
        this = next;
    }

    // Last two chars processing
    rc = pthread_create(&tUpd, NULL, UPD, &this);
    if (rc != 0) fprintf(stderr, "Error creating UPD thread\n");

    rc = pthread_create(&tPrint, NULL, PRINT, &last);
    if (rc != 0) fprintf(stderr, "Error creating PRINT thread\n");

    rc = pthread_join(tUpd, &retv);
    if (rc != 0) fprintf(stderr, "Error joining UPD thread\n");

    rc = pthread_join(tPrint, &retv);
    if (rc != 0) fprintf(stderr, "Error joining PRINT thread\n");

    rc = pthread_create(&tPrint, NULL, PRINT, &this);
    if (rc != 0) fprintf(stderr, "Error creating PRINT thread\n");

    rc = pthread_join(tPrint, &retv);
    if (rc != 0) fprintf(stderr, "Error joining PRINT thread\n");

    return 0;
}