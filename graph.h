#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

typedef struct queueNode {
    pnode nodedata;
    int priority;
    struct queueNode *next;
} qnode;

typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
    int index;
} node, *pnode;

void buildGraphCmd(pnode *head);

void insertNodeCmd(pnode *head);

void deleteNodeCmd(pnode *head);

void printGraphCmd(pnode head);

void deleteGraphCmd(pnode *head);

void shortsPathCmd(pnode head);

void tspCmd(pnode head);

#endif