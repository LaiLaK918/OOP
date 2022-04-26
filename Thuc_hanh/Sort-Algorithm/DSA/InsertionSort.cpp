#include "InsertionSort.h"

InsertionSort::InsertionSort() {

}

InsertionSort::InsertionSort(int nn) {
	n = nn;
	arr = new int[n];
}

InsertionSort::~InsertionSort() {

}

void InsertionSort::Sorted() {
	int i, pos, x;
	for (int i = 1; i < n; ++i) {
		x = arr[i];
		pos = i - 1;
		while (pos >= 0 && arr[pos] > x) {
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = x;
	}
}