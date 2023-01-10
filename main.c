#include <stdio.h>
#include "graph.h"
#include "nodes.h"


int main() {
    char s;
    int k;
    pnode head = NULL;
    while (scanf("%c", &s) != EOF) {
        switch (s) {
            case 'A':
                deleteGraphCmd(&head);
                scanf("%d", &k);
                head = generate(k);
                break;
            case 'n':
                buildGraphCmd(&head);
                break;
            case 'B':
                insertNodeCmd(&head);
                break;
            case 'p':
                printGraphCmd(head);
                break;
            case 'S':
                shortsPathCmd(head);
                break;
            case 'D':
                deleteNodeCmd(&head);
                break;
            case 'T':
                tspCmd(head);
                break;
        }
    }
    deleteGraphCmd(&head);
    return 0;
}