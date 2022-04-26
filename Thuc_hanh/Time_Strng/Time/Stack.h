#ifndef STACK_H
#define STACK_H

#pragma once
#include<iostream>
using namespace std;

#define MAX_SIZE 100

class Stack
{
	int size;
	int array_stack[MAX_SIZE]{ 0 };
public:
	Stack();
	~Stack();
	void Push(int);
	void Pop();
	bool isEmpty();
	bool isFull();
	int getSize();
	int Top();
	int& operator [] (int);
};

#endif // !STACK_H