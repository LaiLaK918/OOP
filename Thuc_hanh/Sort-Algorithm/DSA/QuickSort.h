#pragma once

#ifndef QUICKSORT

#define QUICKSORT

#include "Sort.h"

class QuickSort :
	public Sort
{
public:
	QuickSort();
	QuickSort(int);
	~QuickSort();
	void quickSort(int, int);
	void Sorted();
};

#endif // !QUICKSORT