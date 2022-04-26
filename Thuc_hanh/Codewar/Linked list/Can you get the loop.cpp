// solve.cpp

#include "Node.h"

int getLoopSize(Node* startNode)
{
    Node* turtle = startNode;
    Node* rabbit = startNode->next;
    while (turtle != rabbit) {
        turtle = turtle->next;
        rabbit = rabbit->next->next;
    }
    turtle = turtle->next;
    int count = 1;
    while (turtle != rabbit) {
        turtle = turtle->next;
        count++;
    }
    return count;
}