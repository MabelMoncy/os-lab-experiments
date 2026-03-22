#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex, writeblock;
int data = 0, readcount = 0;

// Reader function
void* reader(void* arg) {
    sem_wait(&mutex);          // Protect readcount
    readcount++;

    if (readcount == 1)
        sem_wait(&writeblock); // First reader blocks writer

    sem_post(&mutex);

    // Reading section
    printf("Reader is reading data = %d\n", data);

    sem_wait(&mutex);
    readcount--;

    if (readcount == 0)
        sem_post(&writeblock); // Last reader allows writer

    sem_post(&mutex);

    return NULL;
}

// Writer function
void* writer(void* arg) {
    sem_wait(&writeblock);  // Writer gets exclusive access

    data++; // Writing
    printf("Writer updated data to %d\n", data);

    sem_post(&writeblock);

    return NULL;
}

int main() {
    pthread_t r1, r2, w1;

    sem_init(&mutex, 0, 1);
    sem_init(&writeblock, 0, 1);

    pthread_create(&r1, NULL, reader, NULL);
    pthread_create(&r2, NULL, reader, NULL);
    pthread_create(&w1, NULL, writer, NULL);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);

    return 0;
}