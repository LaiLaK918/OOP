#pragma once

#ifndef BUBBLESORT

#define BUBBLESORT

#include "Sort.h"

class BubbleSort :
    public Sort
{
public:
    BubbleSort();
    BubbleSort(int);
    ~BubbleSort();
    void Sorted();
};

#endif // !BUBBLESORT