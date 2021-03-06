#include "RadixSort.h"

RadixSort::RadixSort() {

}

RadixSort::RadixSort(int nn) {
    n = nn;
    arr = new int[n];
}

RadixSort::~RadixSort() {

}

int RadixSort::getMax() {
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

void RadixSort::count(int exp) {
	int* output = new int[n]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
	delete[] output;
}

void RadixSort::Sorted() {
	int m = getMax();
	for (int exp = 1; m / exp > 0; exp *= 10) {
		count(exp);
	}
}
