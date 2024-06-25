#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MM      1000000000L
#define THREADS 4

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int global_int = 0;

void* thread_(void* vargp) {
    do {
        //pthread_mutex_lock(&mutex);
        ++global_int;
        //pthread_mutex_unlock(&mutex);

        //printf("\33[2K\rGlobal: %7d | Thread: %ld", global_int, pthread_self());
    } while (global_int < MM);
    return NULL;
}

typedef void* (*threads)(void*);

int main(int argc, char** argv) {

    clock_t start_t, end_t;
    double duration_t;

    pthread_t* t_ids = calloc(THREADS, sizeof(pthread_t));

    for(int i = 0; i < THREADS; i++) {
        pthread_create(&t_ids[i], NULL, &thread_, NULL);
    }
    
    start_t - clock();
    for(int i = 0; i < THREADS; i++) {
        pthread_join(t_ids[i], NULL);
    }
    end_t = clock();
    duration_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("\nTime to count to %ld: %.3f seconds. (THREADS: %d)", MM, duration_t, THREADS);

    exit(EXIT_SUCCESS);
}