#pragma once

#ifndef SHAKERSORT

#define SHAKERSORT

#include "Sort.h"

class ShakerSort :
	public Sort
{
public:
	ShakerSort();
	ShakerSort(int);
	~ShakerSort();
	void Sorted();
};

#endif // !SHAKERSORT