/* This program tries to find way from labyrinth defined 
in file specified as argument. 
Nodes are specified in each row:
node_id, node_type (-1 start, 0 normal, 1 exit), neighbour nodes at N, E, S, W directions
*/
#include "labyrint.h"

int main(int argc, char **argv) {
    node_t *node_arr;
    int *history;
    char f_name[50];
    if ( 1 == argc ) {
        strcpy(f_name,"map.txt");
    }
    else {
        if ( (50 > strlen(*++argv) )) {
            strcpy(f_name, *argv);
        }
        else {
            fprintf(stderr,"File name too long (50 char max)!\n");
            exit(1);
        }
    }
    node_arr = read_map(f_name,&history);
    search(node_arr, 0, 0,&history);
    
    return 0;
}
