#include<iostream>
#include<set>
using namespace std;

struct Node {
	char data;
	Node* prev;
	Node* next;

	Node(char _data = '\0') {
		data = _data;
		prev = NULL;
		next = NULL;
	}
};

struct DList {
	Node* head;
	Node* tail;
	DList() {
		head = NULL;
		tail = NULL;
	}
};

void AddTail(DList&, Node*);

void AddHead(DList&, Node*);

void Input(DList&);

void Print(const DList&);

int Count(const DList&);

char SearchPopularly(const DList&);

bool IsPalind(const DList&);

void Sort(DList&);

void InsertBeforeQ(DList&, Node*, Node*);

void InsertAfterSorted(DList&, Node*);

void Delete(DList&, Node*);

void Delete(DList&, char);

int main() {
	DList lst;
	Input(lst);
	Print(lst);
	//cout << endl << SearchPopularly(lst);
	//Sort(lst);
	cout << endl;
	//InsertAfterSorted(lst, new Node('e'));
	Delete(lst, 'e');
	Print(lst);
}

void AddTail(DList& lst, Node* p) {
	if (lst.head == NULL && lst.tail == NULL) {
		lst.head = lst.tail = p;
	}
	else {
		p->prev = lst.tail;
		lst.tail->next = p;
		lst.tail = p;
	}
}

void AddHead(DList& lst, Node* p) {
	if (lst.head == NULL && lst.tail == NULL) {
		lst.head = p;
		lst.tail = p;
	}
	else {
		p->next = lst.head;
		lst.head->prev = p;
		lst.head = p;
	}
}

void Input(DList& lst) {
	int n;
	cout << "Nhap so node: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;
		AddTail(lst, new Node(x));
	}
}

void Print(const DList& lst) {
	for (Node* p = lst.head; p != NULL; p = p->next) {
		cout << p->data << " ";
	}
}

char SearchPopularly(const DList& lst) {
	set<char> st;
	for (Node* p = lst.head; p != NULL; p = p->next) {
		st.insert(p->data);
	}
	char max = '\0';
	int countMax = 0;
	for (char it : st) {
		int count = 0;
		for (Node* p = lst.head; p != NULL; p = p->next) {
			if (it == p->data) count++;
		}
		if (count > countMax) {
			max = it;
			countMax = count;
		}
	}
	return max;
}

int Count(const DList& lst) {
	int count = 0;
	for (Node* p = lst.head; p != NULL; p = p->next) {
		count++;
	}
	return count;
}

bool IsPalind(const DList& lst) {
	Node* head = lst.head, * tail = lst.tail;
	int endLoop = -1, len = Count(lst);
	while (++endLoop < len / 2) {
		if (head->data != tail->data) return false;
		head = head->next;
		tail = tail->prev;
	}
	return true;
}

void Sort(DList& lst) {
	for (Node* p = lst.head; p != NULL; p = p->next) {
		for (Node* q = p->next; q != NULL; q = q->next)
			if (p->data > q->data) swap(p->data, q->data);
	}
}

void InsertBeforeQ(DList& lst, Node* q, Node* p) {
	if (q->prev == NULL) AddHead(lst, p);
	else {
		Node* tmp = q->prev;
		tmp->next = p;
		p->prev = tmp;
		p->next = q;
		q->prev = p;
	}
}

void InsertAfterSorted(DList& lst, Node* t) {
	Node* p = lst.head;
	for (; p != NULL; p = p->next) {
		if (p->data > t->data) break;
	}
	if (p == NULL) AddTail(lst, t);
	else
		InsertBeforeQ(lst, p, t);
}

void Delete(DList& lst, Node* p) {
	if (p == lst.head) {
		lst.head = lst.head->next;
		lst.head->prev = NULL;
		delete p;
	}
	else if (p == lst.tail) {
		lst.tail = lst.tail->prev;
		lst.tail->next = NULL;
		delete p;
	}
	else {
		Node* q = p->prev;
		q->next = p->next;
		p->next->prev = q;
		delete p;
	}
}

void Delete(DList& lst, char x) {
	Node* p = lst.head;
	while (p != NULL) {
		if (p->data == x) {
			Node* q = p->next;
			Delete(lst, p);
			p = q;
		}
		else p = p->next;
	}
}
