#include "labyrint.h"

int main(void) {
    node_t *node_arr;
    int *history;
    node_arr = read_map("map.txt",&history);
    for (int i = 0; i < 26; i++) {
        printf("%2d, %2d, %2d, %2d, %2d, %2d\n", 
        node_arr[i].id, node_arr[i].type, node_arr[i].N, node_arr[i].E, node_arr[i].S, node_arr[i].W);
    }
    search(node_arr, 0, &history);
    
    return 0;
}
