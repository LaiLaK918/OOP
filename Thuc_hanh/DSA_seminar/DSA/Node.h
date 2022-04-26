// Node.h

#pragma once
class Node {
	Node* next;
public:
	Node() {
		next = 0;
	}
	Node* getNext() {
		return this->next;
	}
};