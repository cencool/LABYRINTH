#include "labyrint.h"

void print_history(int *history) {
    int id, i = 0;
    printf("History of moves for this route:\n");
    while ( (id = *(history+i)) != -1) {
        printf("# %d: %d\n", i+1, id);
        i++;
    }
}

