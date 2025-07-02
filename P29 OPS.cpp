#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX 5

sem_t mutex;
int counter = 0;

void* process(void* arg) {
    int id = *(int*)arg;

    sem_wait(&mutex);
    counter++;
    printf("Process %d: Counter = %d\n", id, counter);
    sem_post(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[MAX];
    int process_ids[MAX];

    sem_init(&mutex, 0, 1);

    for (int i = 0; i < MAX; i++) {
        process_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, process, (void*)&process_ids[i]);
    }

    for (int i = 0; i < MAX; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&mutex);
    return 0;
}

