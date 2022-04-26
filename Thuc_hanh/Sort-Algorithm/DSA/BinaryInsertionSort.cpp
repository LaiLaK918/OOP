#include "BinaryInsertionSort.h"

BinaryInsertionSort::BinaryInsertionSort() {

}

BinaryInsertionSort::BinaryInsertionSort(int nn) {
	n = nn;
	arr = new int[n];
}

BinaryInsertionSort::~BinaryInsertionSort() {

}

void BinaryInsertionSort::Sorted() {
	int l, r, m, i, x;
	for (int i = 1; i < n; i++) {
		x = arr[i];
		l = 0;
		r = i - 1;
		while (l <= r) {
			m = (l + r) / 2;
			if (x < arr[m]) r = m - 1;
			else l = m + 1;
		}
		for (int j = i; j > l; j--) {
			arr[j] = arr[j - 1];
		}
		arr[l] = x;
	}
}
