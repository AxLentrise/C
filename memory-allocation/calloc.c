#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>

int main(int argc, char** argv) {
    uint16_t n = 0;
    uint32_t* int_arr;
    
    if(sscanf(argv[1], "%d", &n) == EOF) {
        exit(EXIT_FAILURE);
    }

    if(!(int_arr = calloc(n, sizeof(uint32_t)))) {
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < n; i++) {
        int_arr[i] = (i + 1);

        printf("#%d = %d\n", i + 1, int_arr[i]);
    }

    free(int_arr);
    exit(EXIT_SUCCESS);
}