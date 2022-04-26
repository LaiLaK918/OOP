#pragma once

#ifndef RADIXSORT

#define RADIXSORT

#include "Sort.h"

class RadixSort :
    public Sort
{
public: 
    RadixSort();
    RadixSort(int);
    ~RadixSort();
    int getMax();
    void count(int);
    void Sorted();
};

#endif // !RADIXSORT