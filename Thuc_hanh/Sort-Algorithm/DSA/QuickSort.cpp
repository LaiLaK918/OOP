#include "QuickSort.h"

QuickSort::QuickSort() {

}

QuickSort::QuickSort(int nn) {
	n = nn;
	arr = new int[n];
}

QuickSort::~QuickSort() {

}

void QuickSort::Sorted() {
	quickSort(0, n - 1);
}

void QuickSort::quickSort(int left, int right) {
	int x, i, j;
	x = arr[(left + right) / 2];
	i = left;
	j = right;
	do {
		while (arr[j] > x) j--;
		while (arr[i] < x) i++;
		if (i <= j) {
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i < j);
	if (left < j) quickSort(left, j);
	if (right > i) quickSort(i, right);
}