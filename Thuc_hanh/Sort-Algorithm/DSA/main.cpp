#include "HeapSort.h"
#include "Sort.h"
#include <iostream>
using namespace std;

#define FILENAME "a.txt"

static void test() {
	fstream f(FILENAME, ios::in); // create a file name "a.txt" in cwd
	int n;
	f >> n;
	HeapSort* h = new HeapSort(n);
	h->input(f);
	h->Sorted();
	h->print();
}

static void testR() {
	HeapSort* h = new HeapSort();
	h->inputRan();
	h->Sorted();
	h->print();
}

int main() {
	testR();
	test();
	return 0;
}

// a.txt
//
// 11
// 3 2 5 1 4 7 9 10 8 12 11