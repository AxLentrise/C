#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(int argc, char** agrv) {
    uint8_t n = 5;
    uint32_t* int_arr = calloc(n, sizeof(uint32_t));

    for(int i = 0; i < n; i++) {
        int_arr[i] = (1 + i) * n;
    }

    int_arr = realloc(int_arr, (2*n* sizeof(uint32_t)));

    for(int i = n; i < 2*n; i++) {
        int_arr[i] = (1 + i) * n;
    }

    for(int i = 0; i < 2*n; i++) {
        printf("#%2d = %2d\n", 1+i, int_arr[i]);
    }

    free(int_arr);
    exit(EXIT_SUCCESS);
}