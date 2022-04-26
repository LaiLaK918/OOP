#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include <iostream>
using namespace std;

#pragma once
template<class _Ty> class List
{
	Node<_Ty>* head;
	Node<_Ty>* tail;
public:
	List();
	List(Node<_Ty>* _head , Node<_Ty>* _tail );
	~List();
	void addTail(const _Ty&);
	void addHead(const _Ty&);
	friend ostream& operator << (ostream&, List&);
	friend istream& operator >> (istream&, List&);
};


#endif // !LIST_H