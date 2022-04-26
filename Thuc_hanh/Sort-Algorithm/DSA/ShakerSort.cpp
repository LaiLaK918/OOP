#include "ShakerSort.h"

ShakerSort::ShakerSort() {

}

ShakerSort::ShakerSort(int nn) {
	n = nn;
	arr = new int[n];
}

ShakerSort::~ShakerSort() {

}

void ShakerSort::Sorted() {
	int j;
	int l = 0, r = n - 1, k = n - 1;
	while (l < r) {
		for (j = r; j > l; j--) {
			if (arr[j] < arr[j - 1]) {
				_swap(arr[j], arr[j - 1]);
				k = j;
			}
		}
		l = k;
		for (int j = l; j < r; j++) {
			if (arr[j] > arr[j + 1]) {
				_swap(arr[j], arr[j + 1]);
				k = j;
			}
		}
		r = k;
	}
}
