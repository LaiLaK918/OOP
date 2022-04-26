#pragma once

#ifndef SELECTIONSORT

#define SELECTIONSORT

#include "Sort.h"

class SelectionSort :
    public Sort
{
public:
    SelectionSort();
    SelectionSort(int);
    ~SelectionSort();
    void Sorted();
};


#endif // !SELECTIONSORT