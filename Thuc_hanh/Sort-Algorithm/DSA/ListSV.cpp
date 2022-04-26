#include <iostream>
#include <string>
using namespace std;

struct SINH_VIEN {
	int ID;
	string name;
	int GPA;
	friend ostream& operator << (ostream& os, SINH_VIEN& sv);
	friend istream& operator >> (istream& is, SINH_VIEN& sv);
};

typedef SINH_VIEN SV;

struct Node {
	SV data;
	Node* next;
};

struct List {
	Node* head;
	Node* tail;
	int len;
};

ostream& operator << (ostream& os, SV& sv) {
	os << "Sinh vien (ID: " << sv.ID << ", ten: " << sv.name << ", GPA: " << sv.GPA << ")\n";
	return os;
}

istream& operator >> (istream& is, SV& sv) {
	cout << "Nhap ID: ";
	is >> sv.ID;
	cout << "Nhap ten: ";
	cin.ignore();
	getline(is, sv.name);
	cout << "Nhap GPA: ";
	is >> sv.GPA;
	return is;
}

Node* CreateNode(SV x) {
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

void insert(List& l, int pos, SV data) {
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

void insertDataBefore(List& l, int dataList_ID, SV dataInsert_ID) {
	Node* tmp = l.head;
	while (tmp != NULL) {
		if (tmp->data.ID == dataList_ID) break;
		tmp = tmp->next;
	}
	if (tmp == NULL) {
		cout << "Khong tim thay gia tri " << dataList_ID << " trong list.\n";
		return;
	}
	else if (tmp == l.tail) AddTail(l, CreateNode(dataInsert_ID));
	else {
		Node* p = CreateNode(dataInsert_ID);
		p->next = tmp->next;
		tmp->next = p;
	}
	l.len++;
}

void insertDataAfter(List& l, int dataList, SV dataInsert) {
	Node* tmp = l.head;
	if (tmp->data.ID == dataList) {
		AddHead(l, CreateNode(dataInsert));
	}
	else {
		while (tmp->next != NULL) {
			if (tmp->next->data.ID == dataList) break;
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

void input(List& l, SV* arr, int size) {
	int i = -1;
	while (++i < size) {
		AddTail(l, CreateNode(*(arr + i)));
	}
	l.len = size;
}

void PrintList(List& l, bool addressNode = false) {
	for (Node* i = l.head; i != NULL; i = i->next) {
		if (addressNode) cout << i << " ";
		cout << i->data;
	}
}

int main()

{

	List l;
	int n;
	cin >> n;
	CreateList(l);
	for (int i = 0; i < n; i++) {
		SV x;
		cin >> x;
		AddTail(l, CreateNode(x));
	}

	PrintList(l);
	return 0;

}