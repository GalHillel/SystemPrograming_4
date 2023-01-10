#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "nodes.h"

void push(qnode **head, pnode d, int p);

int isEmpty(qnode **head);

int peek(qnode **head);

qnode *newQueueNode(pnode data, int p);

pnode pop(qnode **head);