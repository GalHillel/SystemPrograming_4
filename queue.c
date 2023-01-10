#include "queue.h"

qnode *newQueueNode(pnode data, int p) {
    qnode *temp = (qnode *) malloc(sizeof(qnode));
    temp->nodedata = data;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}

pnode pop(qnode **head) {
    pnode temp = (*head)->nodedata;
    qnode *tempToFree = *head;
    (*head) = (*head)->next;
    free(tempToFree);
    return temp;
}

void push(qnode **head, pnode d, int p) {
    qnode *start = (*head);
    qnode *temp = newQueueNode(d, p);
    if (isEmpty(head)) {
        (*head) = temp;
        return;
    }

    if ((*head)->priority > p) {
        temp->next = *head;
        (*head) = temp;
    } else {
        while (start->next != NULL && start->next->priority < p) {
            start = start->next;
        }

        temp->next = start->next;
        start->next = temp;
    }
}

int isEmpty(qnode **head) {
    return (*head) == NULL;
}