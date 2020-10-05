#ifndef LABYRINT_H
#define LABYRINT_H

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define N dir[0]
#define E dir[1]
#define S dir[2]
#define W dir[3]

typedef struct node{
    int id;
    int type;
    int visited;
    int dir[4];
    } node_t;

node_t * read_map(const char *f_name, int **history);
void search(node_t *node_arr, int node_id, int **history) ;
void print_history(int *history);

#endif
