#include "Stack.h"

Stack::Stack() {
	size = 0;
}

Stack::~Stack() {

}

void Stack::Push(int t) {
	if (isFull()) {
		cout << "Stack overflow.";
		return;
	}
	array_stack[size++] = t;
}

void Stack::Pop() {
	if (!isEmpty())
		size--;
	else cout << "Stack is empty.";
}

int Stack::Top() {
	if (!isEmpty())
		return array_stack[size - 1];
	else {
		cout << "Stack is empty";
		return INT16_MIN;
	}
}

bool Stack::isEmpty() {
	return !size;
}

bool Stack::isFull() {
	return size > MAX_SIZE;
}

int& Stack::operator[] (int index) {
	return array_stack[index];
}

int Stack::getSize() {
	return size;
}