#pragma once

#ifndef INSERTIONSORT

#define INSERTIONSORT

#include "Sort.h"

class InsertionSort :
	public Sort
{
public:
	InsertionSort();
	InsertionSort(int);
	~InsertionSort();
	void Sorted();
};

#endif // !INSERTIONSORT