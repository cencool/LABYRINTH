#include "labyrint.h"

void search(node_t *node_arr,int id,int **history) {
   if ( node_arr[id].type == 1) {
       printf("Exit found\n");
       print_history(*history);
       return;
   }
   else if (node_arr[id].visited == 1) {
       //printf("Node %d already visited\n", id);
       return;
   }
   else {
       node_arr[id].visited = 1;
       int j=0;
       for (int i = 0; i < 4; i++) {
           if (node_arr[id].dir[i] != -1) {
               while( *(*history+j) != -1){ // to find end of history
                   j++;
               }
               *(*history+j) = id; // add move to history
               search(node_arr, node_arr[id].dir[i], history);
               *(*history+j) = -1; // delete move from history
           }
        }
        node_arr[id].visited = 0;
        return;
   }
       
}
    
