#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

typedef struct node {
    uint32_t value;
    struct node* next;
} node;

int main(int argc, char** argv) {
    node* ptr = malloc(sizeof(node));

    ptr->value = 10;
    ptr->next = NULL;

    printf("Value: %d", ptr->value);

    free(ptr);
    exit(EXIT_SUCCESS);
}