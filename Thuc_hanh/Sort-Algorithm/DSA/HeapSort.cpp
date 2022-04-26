#include "HeapSort.h"

HeapSort::HeapSort() {

}

HeapSort::HeapSort(int nn) {
	n = nn;
	arr = new int[n];
}

HeapSort::~HeapSort() {
	
}

//void HeapSort::Shift(int left, int right) {
//	int x, j, i;
//	i = left;
//	j = 2 * i + 1;
//	x = arr[i];
//	while (j <= right) {
//		if (j < right) if (arr[j] < arr[j + 1]) j++;
//		if (x < arr[j]) return;
//		else {
//			arr[i] = arr[j];
//			arr[j] = x;
//			i = j;
//			j = 2 * i + 1;
//			x = arr[i];
//		}
//	}
//}
//
//void HeapSort::CreateHeap(int n) {
//	int left = n / 2 - 1;
//	while (left >= 0)
//	{
//		Shift(left, n - 1);
//		left--;
//	}
//}
//
//void HeapSort::Sorted() {
//	int right = n - 1;
//	CreateHeap(n);
//	while (right > 0) {
//		_swap(arr[0], arr[right]);
//		right--;
//		if (right > 0) CreateHeap(right);
//	}
//}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void HeapSort::heapify(int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		_swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(n, largest);
	}
}

// main function to do heap sort
void HeapSort::Sorted()
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		_swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(i, 0);
	}
}
