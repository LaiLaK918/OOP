#pragma once
#ifndef MERGESORT
#define MERGESORT

#include "Sort.h"
class MergeSort :
    public Sort
{
public:
    MergeSort();
    MergeSort(int);
    ~MergeSort();
    void Merge(int, int, int);
    void mergeSort(int, int);
    void Sorted();
};

#endif