#ifndef NODE_H
#define NODE_H
#include <iostream>

#pragma once
template<class _Ty> class Node
{
	_Ty data;
	Node<_Ty>* next;
public:
	Node();
	Node(_Ty);
	~Node();
};


#endif // !NODE_H