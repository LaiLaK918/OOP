#include <iostream>
using namespace std;
#define MAXSIZE 1000

bool ISRUNNING = true;

 struct Node {
	int data;
	Node* next;
	Node(int _data = 0) {
		data = _data;
		next = NULL;
	}
};

 struct _queue {
	Node* head;
	Node* tail;
	int size;
	_queue() {
		head = tail = NULL;
		size = 0;
	}
};

 void _enQueue(_queue& l, int data) {
	Node* p = new Node(data);
	if (l.tail == NULL) {
		l.head = p;
		l.tail = p;
	}
	else {
		l.tail->next = p;
		l.tail = p;
	}
	l.size++;
}

 bool _isEmpty(const _queue& q) {
	return q.head == NULL;
}

 bool _isFull(const _queue& q) { // đầy bộ nhớ
	 return q.size >= MAXSIZE;
 }

 bool _deQueue(_queue& q) {
	if (!_isEmpty(q)) {
		Node* p = q.head;
		q.head = q.head->next;
		if (q.head == NULL) q.tail = NULL;
		delete p;
		q.size--;
		return true;
	}
	return false;
}

 int _front(const _queue& q) { // lấy front
	if (!_isEmpty(q)) {
		return q.head->data;
	}
}

 int _back(const _queue& q) { // lấy rear
	if (!_isEmpty(q)) return q.tail->data;
}

 void test() {
	 _queue qi;
	 _enQueue(qi, 2);
	 _enQueue(qi, 3);
	 _enQueue(qi, 1);
	 _enQueue(qi, 9);
	 _enQueue(qi, 12);
	 _enQueue(qi, 22);
	 _enQueue(qi, 13);
	 _enQueue(qi, 8);
	 _enQueue(qi, 122);
	 _enQueue(qi, 1);
	 _enQueue(qi, 0);
	 _enQueue(qi, 29);
	 _enQueue(qi, -1);
	 _deQueue(qi);
	 cout << _front(qi) << " " << _back(qi);
 }

 _queue st;

 void menu() {
	 cout << "Options: ";
	 cout << "\n1. Create new queue(remove current queue).";
	 cout << "\n2. Check empty.";
	 cout << "\n3. Check full.";
	 cout << "\n4. Enqueue.";
	 cout << "\n5. Dequeue.";
	 cout << "\n6. Rear.";
	 cout << "\n7. Front.";
	 cout << "\n8. Exit.\n";
	 cout << "Input: ";
	 int options = 0;
	 cin >> options;
	 switch (options)
	 {
	 case 1:
		 st = _queue();
		 break;
	 case 2:
		 if (_isEmpty(st)) {
			 cout << "Empty queue.\n";
		 }
		 else cout << "Queue is not empty.\n";
		 break;
	 case 3:
		 if (_isFull(st)) {
			 cout << "Queue is full.\n";
		 }
		 else {
			 cout << "Queue is not full.\n";
		 }
		 break;
	 case 4:
		 cout << "Enter an integer: ";
		 int in;
		 cin >> in;
		 _enQueue(st, in);
		 break;
	 case 5:
		 _deQueue(st);
		 break;
	 case 6:
		 cout << _back(st);
		 break;
	 case 7:
		 cout << _front(st);
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

int main() {
	while (ISRUNNING) {
		menu();
	}
	return 0;
}