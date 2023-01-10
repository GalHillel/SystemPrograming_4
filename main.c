#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

//#include "algo.c"
//#include "edges.h"
#include "graph.h"
#include "nodes.h"
//#include "queue.h"


int main() {
    char s;
    int k;
    pnode head = NULL;
    while (scanf("%c", &s) != EOF) {
        switch (s) {
            case 'A':
                deleteGraph_cmd(&head);
                scanf("%d", &k);
                head = generate(k);
                break;
            case 'n':
                build_graph_cmd(&head);
                break;
            case 'B':
                insert_node_cmd(&head);
                break;
            case 'p':
                printGraph_cmd(head);
                break;
            case 'S':
                shortsPath_cmd(head);
                break;
            case 'D':
                delete_node_cmd(&head);
                break;
            case 'T':
                TSP_cmd(head);
                break;
        }
    }
    deleteGraph_cmd(&head);
    return 0;
}