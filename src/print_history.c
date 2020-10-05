#include "labyrint.h"

void print_history(int *history) {
    int id, i = 0;
    while ( (id = *(history+i)) != -1) {
        printf("# %d: %d\n", i+1, id);
        i++;
    }
}

