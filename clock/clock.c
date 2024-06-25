#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

int main(int argc, char** argv) {
    clock_t start_t, end_t;
    double total_t;

    start_t = clock();
    printf("Program start clock: %ld", start_t);
    
    for(uint64_t i = 0; i < 1000000L; ++i) {
        printf("\33[2K\rClocks: %7d", i);
    }

    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("\nFinal time: %.3f", total_t);

    exit(EXIT_SUCCESS);
}