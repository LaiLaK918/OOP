#include <iostream>
using namespace std;

bool ISRUNNING = true;

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
	Node* p = new Node(0);
	return p == NULL;
}

bool _pop(_stack& s) {
	Node* p;
	if (!_isEmpty(s)) {
		p = s.head;
		s.head = s.head->next;
		if (s.head == NULL) s.tail = NULL;
		delete p;
		return true;
	}
	return false;
}

int _top(const _stack& s) {
	if (!_isEmpty(s)) return s.head->data;
	else return INT_MAX;
}

void print(Node* head) {
	Node* p = head;
	if (p == NULL) {
		return;
	}
	else {
		int data = p->data;
		print(p->next);
		cout << data << "\t";
	}
}

void print(const _stack& st) {
	cout << "Stack = < ";
	print(st.head);
	cout << ">\n";
	cout << "============================================\n";
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
	print(st.head);
}

void move(_stack& source, _stack& desti) {
	if (_top(source) < _top(desti) && !_isEmpty(source)) {
		_push(desti, _top(source));
		_pop(source);
	}
	else {
		cout << "Can't move.\n";
	}
}

void print(_stack A, _stack B, _stack C) {
	cout << "A Tower\n";
	print(A);
	cout << "B tower\n";
	print(B);
	cout << "C tower\n";
	print(C);
}

void play(_stack& towerA, _stack& towerB, _stack& towerC) {
	cout << "==================Stack=====================\n";
	cout << "\t\t0. Creating tower.\n";
	cout << "\t\t1. A->B.\n";
	cout << "\t\t2. B->A.\n";
	cout << "\t\t3. B->C.\n";
	cout << "\t\t4. C->B.\n";
	cout << "\t\t5. C->A.\n";
	cout << "\t\t6. A->C.\n";
	cout << "\t\t7. End game.\n";
	cout << "============================================\n";
	print(towerA, towerB, towerC);
	cout << "Input: ";
	int option = 0;
	cin >> option;
	switch (option)
	{
	case 1:
		move(towerA, towerB);
		break;
	case 2:
		move(towerB, towerA);
		break;
	case 3:
		move(towerB, towerC);
		break;
	case 4:
		move(towerC, towerB);
		break;
	case 5:
		move(towerC, towerA);
		break;
	case 6:
		move(towerA, towerC);
		break;
	case 7:
		ISRUNNING = false;
		break;
	default:
		cout << "Invalit option!\n";
		break;
	}
}

void solve(_stack& source, _stack& desti, _stack& auxiliary, int level) {
	if (level > 0) {
		solve(source, auxiliary, desti, level - 1); // move n-1 disks from source to auxiliary
		_push(desti, _top(source));
		_pop(source);
		//print(source, auxiliary, desti);
		solve(auxiliary, desti, source, level - 1);
	}
}

int main() {
	_stack A, B, C;
	_push(A, 6);
	_push(A, 5);
	_push(A, 4);
	_push(A, 3);
	_push(A, 2);
	_push(A, 1);
	//while (ISRUNNING) { // chơi
	//	play(A, B, C);
	//}
	solve(A, C, B, 5); // tự giải
	print(A, B, C);
	return 0;
}