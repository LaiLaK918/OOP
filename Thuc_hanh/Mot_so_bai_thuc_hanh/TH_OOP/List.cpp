#include "List.h"

template <class _Ty> List<_Ty>::List() {

}

template <class _Ty> List<_Ty>::List(Node<_Ty>* _head, Node<_Ty>* _tail) {
	head = _head;
	tail = _tail;
}

template <class _Ty> List<_Ty>::~List() {

}

template <class _Ty> void List<_Ty>::addHead(const _Ty &data) {
	Node<_Ty>* p = new Node<_Ty>(data);
	if (head == NULL) {
		head = p;
		tail = p;
	}
	else {
		p->next = head;
		head = p;
	}
}

template <class _Ty> void List<_Ty>::addTail(const _Ty &data) {
	Node<_Ty>* p = new Node<_Ty>(data);
	if (head == NULL) {
		head = p;
		tail = p;
	}
	else {
		p->next = head;
		head = p;
	}
}

template<class _Ty> ostream& operator << (ostream& os, List<_Ty>& lst) {
	Node<_Ty>* p = lst.head;
	while (p != NULL) {
		os << p->date << " ";
		p = p->next;
	}
	return os;
}

template <class _Ty> istream& operator >> (istream& is, List<_Ty>& lst) {
	cout << "Nhap so luong node: ";
	int number;
	is >> number;
	while (number-- > 0) {
		int tmp;
		is >> tmp;
		lst.addTail(tmp);
	}
	return is;
}