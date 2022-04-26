// solve.cpp

#include "Node.h"

int getLoopSize(Node* startNode)
{
    Node* turtle = startNode;
    Node* rabbit = startNode->getNext();
    while (turtle != rabbit) {
        turtle = turtle->getNext();
        rabbit = rabbit->getNext()->getNext();
    }
    turtle = turtle->getNext();
    int count = 1;
    while (turtle != rabbit) {
        turtle = turtle->getNext();
        count++;
    }
    return count;
}
