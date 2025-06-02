//12.1.9
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUCCESS 0
#define FAIL 1

typedef struct {
    unsigned int size_dom;
    unsigned int size_cod;
    unsigned int *map;
} NURELM;

char nurelm_rand_map(NURELM *to_redef, unsigned int size_d, unsigned int size_cod) {
    if (size_d == 0 || size_cod == 0) {
        return FAIL;
    }

    if (to_redef->map != NULL) {
        free(to_redef->map);
        to_redef->map = NULL;
    }

    to_redef->map = (unsigned int *)malloc(size_d * sizeof(unsigned int));
    if (to_redef->map == NULL) {
        return FAIL;
    }

    for (unsigned int i = 0; i < size_d; i++) {
        to_redef->map[i] = rand() % size_cod;
    }

    to_redef->size_dom = size_d;
    to_redef->size_cod = size_cod;

    return SUCCESS;
}

int main() {
    srand(time(NULL));

    NURELM mymap;
    mymap.map = NULL;
    mymap.size_dom = 0;
    mymap.size_cod = 0;

    unsigned int d = 8;
    unsigned int c = 5;

    if (nurelm_rand_map(&mymap, d, c) == SUCCESS) {
        printf("Zobrazenie Z%u -> Z%u:\n", d, c);
        for (unsigned int i = 0; i < mymap.size_dom; i++) {
            printf("%u -> %u\n", i, mymap.map[i]);
        }
    } else {
        printf("Nepodarilo sa vytvoriť zobrazenie.\n");
    }

    free(mymap.map);
    return 0;
}
