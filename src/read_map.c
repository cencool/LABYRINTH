#include "labyrint.h"

int count_lines(FILE *fp) {
    int ch, line_count = 1;
    while ( (ch=fgetc(fp)) != EOF) {
        if ( ch == '\n') {
        line_count++;
        }
    }
    rewind(fp);
    return line_count;
}

node_t * read_map(const char *f_name, int **history) {
    FILE *fp = fopen(f_name, "r");
    if (fp == NULL) {
        fprintf(stderr,"fopen ERROR\n");
        exit(1);
    }
    int node_cnt = count_lines(fp);
    /*
    fscanf(fp,"%d",&node_cnt);
    */
    printf("Node cnt:%d\n",node_cnt);
    if ( (*history = malloc((sizeof(int)*(2*node_cnt))+2)) == NULL) {
        fprintf(stderr,"Malloc for history failed\n");
        exit(1);
    }
    else { // clear history
        for (int i = 0; i < node_cnt; i++) {
            (*history)[i] = -1;
        }
    }
    node_t *node_arr;
    node_arr = malloc(sizeof(*node_arr)*node_cnt);
        if (node_arr == NULL) {
            fprintf(stderr,"node_arr malloc ERROR\n");
            exit(1);
        }
        else { 
            for(int i = 0; i < node_cnt; i++) {
                node_arr[i].id = -1;
                node_arr[i].type = -2;
                node_arr[i].visited = 0;
                node_arr[i].N = node_arr[i].E = node_arr[i].S = node_arr[i].W = -1;
            }
        }

    int id_i, type_i, Ni, Ei, Si, Wi, matched;
    for (int i = 0 ; i < node_cnt; i++) {
        matched = fscanf(fp,"%d,%d,",&id_i, &type_i);
        if (matched != 2) {
            fprintf(stderr,"Incorrect format on line: %d\n",i );
            exit(1);
        }
        assert((id_i > -1) && (id_i < node_cnt));

        if ( node_arr[id_i].id != -1) {
            fprintf(stderr,"Double entry for node %d\n",id_i);
            exit(1);
        }
        else if ((type_i != -1) && (type_i != 0) && (type_i != 1)){
            fprintf(stderr,"Incorrect type in node %d\n",id_i);
            exit(1);
        }
        else {
            node_arr[id_i].id = id_i;
            node_arr[id_i].type = type_i;
        }
        matched = fscanf(fp,"%d,%d,%d,%d",&Ni, &Ei, &Si, &Wi);
        if (matched != 4) {
            fprintf(stderr,"Incorrect format on line: %d, item: %d\n",i, id_i);
            exit(1);
        }
        if ( !(Ni < node_cnt)) {
            fprintf(stderr,"node %d reffers to non existing node %d\n", id_i, Ni);
            exit(1);
        }
        else {
        node_arr[id_i].N = Ni;
        }
        if ( !(Ei < node_cnt)) {
            fprintf(stderr,"node %d reffers to non existing node %d\n", id_i, Ei);
            exit(1);
        }
        else {
        node_arr[id_i].E = Ei;
        }
        if ( !(Si < node_cnt)) {
            fprintf(stderr,"node %d reffers to non existing node %d\n", id_i, Si);
            exit(1);
        }
        else {
        node_arr[id_i].S = Si;
        }
        if ( !(Wi < node_cnt)) {
            fprintf(stderr,"node %d reffers to non existing node %d\n", id_i, Wi);
            exit(1);
        }
        else {
        node_arr[id_i].W = Wi;
        }
    }
    // verification of node paths integrity
    for (int i = 0; i < node_cnt; i++) {
        if ( (node_arr[i].N > 0) && (i != node_arr[node_arr[i].N].S) ){
            fprintf(stderr,"N of node %d does not match with S of node %d\n",i,node_arr[i].N);
            exit(1);
        }
        else if ( (node_arr[i].E > 0) && (i != node_arr[node_arr[i].E].W)) {
            fprintf(stderr,"E of node %d does not match with W of node %d\n",i,node_arr[i].E);
            exit(1);
        }
        else if ( (node_arr[i].S > 0) && (i != node_arr[node_arr[i].S].N)) {
            fprintf(stderr,"S of node %d does not match with N of node %d\n",i,node_arr[i].S);
            exit(1);
        }
        else if ( (node_arr[i].W > 0) && (i != node_arr[node_arr[i].W].E)) {
            fprintf(stderr,"W of node %d does not match with E of node %d\n",i,node_arr[i].W);
            exit(1);
        }
    }
    printf("Read map data:\n");
    for (int i = 0; i < node_cnt; i++) {
        printf("%2d, %2d, %2d, %2d, %2d, %2d\n", 
        node_arr[i].id, node_arr[i].type, node_arr[i].N, node_arr[i].E, node_arr[i].S, node_arr[i].W);
    }

    fclose(fp);
    return node_arr;
}
