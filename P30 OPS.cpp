#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* threadFunction(void* arg) {
    printf("Thread is running.\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;


    if (pthread_create(&thread, NULL, threadFunction, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }


    if (pthread_join(thread, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }


    pthread_t thread2;
    if (pthread_create(&thread2, NULL, threadFunction, NULL)) {
        fprintf(stderr, "Error creating second thread\n");
        return 1;
    }
    if (pthread_equal(thread, thread2)) {
        printf("Threads are equal.\n");
    } else {
        printf("Threads are not equal.\n");
    }

    pthread_exit(NULL);
    return 0;
}

