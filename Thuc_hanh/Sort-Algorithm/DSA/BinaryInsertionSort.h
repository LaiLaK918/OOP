#pragma once

#ifndef BINARYINSERTIONSORT

#define BINARYINSERTIONSORT

#include "Sort.h"

class BinaryInsertionSort :
	public Sort
{
public:
	BinaryInsertionSort();
	BinaryInsertionSort(int);
	~BinaryInsertionSort();
	void Sorted();
};

#endif // !BINARYINSERTIONSORT