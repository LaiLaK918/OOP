#pragma once

#ifndef HEAPSORT

#define HEAPSORT

#include "Sort.h"

class HeapSort :
	public Sort
{
public:
	HeapSort();
	HeapSort(int);
	~HeapSort();
	void heapify(int, int);
	void Sorted();
};

#endif // !HEAPSORT