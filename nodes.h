#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void removeOutEdges(pnode here);

void removeSource(int data, pnode here);

pnode generate(int k);

pnode newNode(int k, pnode next);

pnode findNode(int data, pnode head);

pnode insertNode(int data, pnode *head);

pnode newEdge(int weight, pedge next, pnode dest);
