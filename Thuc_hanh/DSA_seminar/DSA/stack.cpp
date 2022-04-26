//MSSV: 21522090
//Họ và tên: Lê Xuân Hoàng
//Buổi 03 - Bài 01


#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

#define MAXSIZE 1000

bool ISRUNNING = true;

bool IS_PRINT_BEFORE = false;

struct Node {
	int data;
	Node* next;
	Node(int _data = 0) {
		data = _data;
		next = NULL;
	}
};

 struct _stack {
	Node* head;
	Node* tail;
	int size;
	_stack() {
		head = tail = NULL;
		size = 0;
	}
};

_stack st;

 void _push(_stack& l, int data) {
	Node* p = new Node(data);
	if (l.head == NULL) {
		l.head = p;
		l.tail = l.head;
	}
	else {
		p->next = l.head;
		l.head = p;
	}
	l.size++;
}

 bool _isEmpty(const _stack& s) {
	return s.head == NULL;
}

 bool _isFull(const _stack& s) {
	 return s.size >= MAXSIZE;
}

 bool _pop(_stack& s) {
	Node* p;
	if (!_isEmpty(s)) {
		p = s.head;
		s.head = s.head->next;
		if (s.head == NULL) s.tail = NULL;
		delete p;
		s.size--;
		return true;
	}
	return false;
}

 int _top(const _stack& s) {
	if (!_isEmpty(s)) return s.head->data;
}

 void print(_stack s) {
	if (_isEmpty(s)) {
		return;
	}
	else {
		int curr = _top(s);
		_pop(s);
		print(s);
		cout << curr << ' ';
	}
	IS_PRINT_BEFORE = true;
}

void menu() {
	cout << "Options: ";
	cout << "\n1. Create new stack(remove current stack).";
	cout << "\n2. Check empty.";
	cout << "\n3. Check full.";
	cout << "\n4. Push.";
	cout << "\n5. Pop.";
	cout << "\n6. Top.";
	cout << "\n7. Print.";
	cout << "\n8. Exit.\n";
	int options = 0;
	cin >> options;
	switch (options)
	{
	case 1:
		st = _stack();
		break;
	case 2:
		if (_isEmpty(st)) {
			cout << "Empty stack.\n";
		}
		else cout << "Stack is not empty.\n";
		break;
	case 3:
		if (_isFull(st)) {
			cout << "Stack is full.\n";
		}
		else {
			cout << "Stack is not full.\n";
		}
		break;
	case 4:
		cout << "Enter an integer: ";
		int in;
		cin >> in;
		_push(st, in);
		break;
	case 5:
		_pop(st);
		break;
	case 6:
		cout << _top(st);
		break;
	case 7:
		//if (!IS_PRINT_BEFORE) {
		//	print(st);
		//}
		print(st);
		break;
	case 8:
		ISRUNNING = false;
		break;
	default:
		cout << "Invalid option!\n";
		break;
	}
	cout << "\n\n";
}

void test() {
	_stack st;
	_push(st, 1);
	_push(st, 2);
	_push(st, 3);
	_push(st, 4);
	_push(st, 5);
	_push(st, 6);
	_push(st, 7);
	_push(st, 8);
	_push(st, 9);
	_push(st, 10);
	_push(st, 11);
	print(st);
}

int main() {
	// ISRUNNING = false;
	while (ISRUNNING) {
		menu();
	}
	return 0;
}