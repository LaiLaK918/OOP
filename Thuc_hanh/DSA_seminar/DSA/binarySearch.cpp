#include <iostream>
using namespace std;

int binarySearch(int A[], int left, int right, int x) {
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (A[mid] == x) return mid;
		if (A[mid] > x) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}

bool isInArray(int A[], int size, int x) {
	int i = binarySearch(A, 0, size - 1, x);
	return i + 1;
}

void searchOne(int A[], int size, int x) {
	cout << binarySearch(A, 0, size - 1, x);
}

void searchAll(int A[], int size, int x) {
	int  i = 0;
	while (i < size) {
		i = binarySearch(A, 0, size - 1, x);
		if (!(i + 1) {
			cout << i;
		}
		else break;
			i++;
	}
}

long _sqrt(long n) {
	long right = n - 1, left = 0;
	int res = 0;
	while (left <= right) {
		res = left + (right - left) / 2;
		if (res * res == n) return res;
		if (res * res < n) right = res - 1;
		else left = right + 1;
	}
	return -1;
}

int main() {
	int A[] = { 1,2,2,4,5,5,5,8,9 };
	int x;
	cin >> x;
	cout << isInArray(A, sizeof(A) / sizeof(A[0]), x);
	cout << endl;
	searchOne(A, sizeof(A) / sizeof(A[0]), x);
	searchAll(A, sizeof(A) / sizeof(A[0]), x);
}