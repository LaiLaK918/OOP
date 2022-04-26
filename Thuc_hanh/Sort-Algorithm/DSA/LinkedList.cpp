#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

struct List {
	Node* head;
	Node* tail;
	int len;
};

Node* CreateNode(int x) {
	Node* p = new Node;
	if (p == NULL) exit(1);
	p->data = x;
	p->next = NULL;
	return p;
}

void AddHead(List& l, Node* p) {
	if (l.head == NULL) {
		l.head = p;
		l.tail = l.head;
	}
	else {
		p->next = l.head;
		l.head = p;
	}
	l.len++;
}

void AddTail(List& l, Node* p) {
	if (l.tail == NULL) {
		l.head = p;
		l.tail = p;
	}
	else {
		l.tail->next = p;
		l.tail = p;
	}
	l.len++;
}

void CreateList(List& l) {
	l.head = NULL;
	l.tail = NULL;
	l.len = 0;
}

void insert(List& l, int pos, int data) {
	if (l.head == NULL) return;
	if (pos == 0) {
		AddHead(l, CreateNode(data));
		return;
	}
	else if (pos == l.len - 1) {
		AddTail(l, CreateNode(data));
		return;
	}
	Node* tmp = l.head;
	for (int i = 0; i < pos - 1; i++) {
		tmp = tmp->next;
	}
	Node* p = CreateNode(data);
	p->next = tmp->next;
	tmp->next = p;
	l.len++;
}

void insertDataBefore(List& l, int dataList, int dataInsert) {
	Node* tmp = l.head;
	while (tmp != NULL) {
		if (tmp->data == dataList) break;
		tmp = tmp->next;
	}
	if (tmp == NULL) {
		cout << "Khong tim thay gia tri " << dataList << " trong list.\n";
		return;
	}
	else if (tmp == l.tail) AddTail(l, CreateNode(dataInsert));
	else {
		Node* p = CreateNode(dataInsert);
		p->next = tmp->next;
		tmp->next = p;
	}
	l.len++;
}

void insertDataAfter(List& l, int dataList, int dataInsert) {
	Node* tmp = l.head;
	if (tmp->data == dataList) {
		AddHead(l, CreateNode(dataInsert));
	}
	else {
		while (tmp->next != NULL) {
			if (tmp->next->data == dataList) break;
			tmp = tmp->next;
		}
		if (tmp == l.tail) {
			cout << "Khong tim thay gia tri " << dataList << " trong list.\n";
			return;
		}
		else {
			Node* p = CreateNode(dataInsert);
			p->next = tmp->next;
			tmp->next = p;
		}
	}
	l.len++;
}

void insertAfterQ(List& l, Node* p, Node* q) {
	if (q != NULL) {
		p->next = q->next;
		q->next = p;
		if (l.tail == q) {
			l.tail = p;
		}
	}
	else AddHead(l, p);
	l.len++;
}

void input(List& l, int* arr, int size) {
	int i = -1;
	while (++i < size) {
		AddTail(l, CreateNode(*(arr + i)));
	}
	l.len = size;
}

void PrintList(List& l, bool addressNode = false) {
	for (Node* i = l.head; i != NULL; i = i->next) {
		if (addressNode) cout << i << " ";
		cout << i->data << "\t";
	}
}

int main()

{

	List l;
	CreateList(l);
	//int n;
	//cin >> n;
	//CreateList(l);
	//for (int i = 0; i < n; i++) {
	//	int x;
	//	cin >> x;
	//	AddTail(l, CreateNode(x));
	//}

	int arr[] = { 1,2,3,4 };
	input(l, arr, 4);
	insertDataBefore(l, 1, 2);
	insertDataAfter(l, 5, 10);
	PrintList(l);
	return 0;

}