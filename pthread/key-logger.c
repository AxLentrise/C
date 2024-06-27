#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include <windows.h>

// Global variables
static uint8_t executing = 1;
static uint32_t user_inputs = 0;
static uint32_t number_pressed = 0;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// key codes
#define PRESSED -32767

void* key_number_listener(void* vargp) {
    do {
        //pthread_mutex_lock(&mutex);
        for(int i = 47; i < 58; i++) {
            number_pressed = i;
        }
        //pthread_mutex_unlock(&mutex);

        sleep(0.100);
    } while(executing);
}

void* key_logger_printer(void* vargp) {
    do {
        //pthread_mutex_lock(&mutex);
        if(number_pressed > 47 && number_pressed < 58) {
            number_pressed -= 48;
            ++user_inputs;
            printf("\33[2K\rNumber pressed: %d", number_pressed);
        } else printf("\33[2K\rNumber pressed: none");
        //pthread_mutex_unlock(&mutex);

        sleep(0.5);
    } while(executing);
}

int main(int argc, char** argv) {
    pthread_t listener, printer;
    uint32_t n = 0;

    pthread_create(&listener, NULL, &key_number_listener, NULL);
    pthread_create(&printer, NULL, &key_logger_printer, NULL);
    pthread_join(listener, NULL);
    pthread_join(printer, NULL);

    do {
        ++n;
        if(n > 10000L) executing = 0;
    } while(executing);

    printf("\n\nNumber of executions: %d | Number of iterations: %d", n, user_inputs);

    exit(EXIT_SUCCESS);
}