#include <iostream>
using namespace std;

bool isInArray(int A[], int size, int x) {
	for (int i = 0; i < size; i++) {
		if (A[i] == x) return true;
	}
	return false;
}

void searchOne(int A[], int size, int x) {
	for (int i = 0; i < size; i++) {
		if (A[i] == x) {
			cout << i;
			break;
		}
	}
}

void searchAll(int A[], int size, int x) {
	for (int i = 0; i < size; i++) {
		if (A[i] == x) cout << i << " ";
	}
}

bool isInArray_2(int A[], int size, int x) {
	A[size] = x;
	int i = 0;
	while (A[i++] != x);
	if (i < size) return true;
	return false;
}

void searchOne_2(int A[], int size, int x) {
	A[size] = x;
	int i = 0;
	while (A[i++] != x);
	if (i < size) cout << i;
	else cout << -1;
}

void searchAll_2(int A[], int size, int x) {
	searchAll(A, size, x);
}

int main() {
	int A[] = { 2,2,5,3,0,6,8,5,1 };
	int x;
	cin >> x;
	cout << isInArray(A, sizeof(A) / sizeof(A[0]), x) << endl;
	searchOne(A, sizeof(A) / sizeof(A[0]), x);
	cout << endl;
	searchAll(A, sizeof(A) / sizeof(A[0]), x);
	return 0;
}