#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "algo.c"
#include "graph.h"
#include "nodes.h"
#include "queue.h"

void buildGraphCmd(pnode *head) {
    int i;
    scanf("%d", &i);
    pnode source = findNode(i, *head);
    pedge prev = NULL;
    while (scanf("%d", &i) == 1) {
        pnode dest = findNode(i, *head);
        scanf("%d", &i);
        prev = newEdge(i, prev, dest);
    }
    source->edges = prev;
}

void insertNodeCmd(pnode *head) {
    int i;
    scanf("%d", &i);
    pnode source = findNode(i, *head);
    if (*head == NULL) {
        *head = newNode(i, NULL);
        source = *head;
    } else if (source != NULL) {
        removeOutEdges(source);
    } else {
        source = insertNode(i, head);
    }
    pedge prev = NULL;
    while (scanf("%d", &i) == 1) {
        pnode dest = findNode(i, *head);
        scanf("%d", &i);
        prev = newEdge(i, prev, dest);
    }
    source->edges = prev;
}

void deleteNodeCmd(pnode *head) {
    int i;
    scanf("%d", &i);
    pnode checkNode = *head;
    pnode delete = NULL;
    if (checkNode->node_num == i) {
        *head = (checkNode->next);
        delete = checkNode;
    } else {
        while (checkNode->next) {
            if (checkNode->next->node_num == i) {
                delete = checkNode->next;
                checkNode->next = delete->next;
                break;
            }
            checkNode = checkNode->next;
        }
    }
    checkNode = *head;
    while (checkNode) {
        removeSource(i, checkNode);
        checkNode = checkNode->next;
    }
    removeOutEdges(delete);
    free(delete);
}

void printGraphCmd(pnode head) {  //for self debug
    while (head) {
        printf("node id: %d\n", head->node_num);
        pedge source = head->edges;
        while (source) {
            printf("%d -> %d   w: %d\n", head->node_num, source->endpoint->node_num, source->weight);
            source = source->next;
        }
        head = head->next;
    }
}

void deleteGraphCmd(pnode *head) {
    pnode source = *head;
    while (source) {
        removeOutEdges(source);
        pnode delete = source;
        source = source->next;
        free(delete);
    }
}

void shortsPathCmd(pnode head) {
    int src;
    int dest;
    int got = 0;
    while (got == 0) {
        got = scanf("%d", &src);
    }
    got = 0;
    while (got == 0) {
        got = scanf("%d", &dest);
    }
    pnode source;
    pnode curr = head;
    int j = 0;
    int dst_index;
    int src_index;
    while (curr) {
        curr->index = j;
        if (curr->node_num == src) {
            source = curr;
            src_index = j;
        }
        if (curr->node_num == dest) {
            dst_index = j;
        }
        j++;
        curr = curr->next;
    }
    int *arr = (int *) malloc(sizeof(int) * j);
    for (int i = 0; i < j; i++) {
        arr[i] = INT_MAX;
    }
    arr[src_index] = 0;
    dijkstra(arr, source);
    printf("Dijsktra shortest path: %d \n", arr[dst_index] < INT_MAX ? arr[dst_index] : -1);
    free(arr);
}

void tspCmd(pnode head) {
    int j;
    scanf("%d", &j);
    int *cities = (int *) malloc(sizeof(int) * j);
    for (int i = 0; i < j; i++) {
        scanf("%d", &cities[i]);
    }
    int number_of_nodes = 0;
    pnode source = head;
    while (source) {
        source->index = number_of_nodes;
        number_of_nodes++;
        source = source->next;
    }
    int ans = INT_MAX;
    permutation(cities, 0, j - 1, number_of_nodes, &ans, head);
    printf("TSP shortest path: %d \n", ans != INT_MAX ? ans : -1);
    free(cities);
}