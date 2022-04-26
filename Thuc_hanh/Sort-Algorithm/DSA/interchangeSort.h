#pragma once

#ifndef INTERCHANGESORT

#define INTERCHANGESORT

#include "Sort.h"

class interchangeSort :
    public Sort
{
public: 
    interchangeSort();
    interchangeSort(int);
    ~interchangeSort();
    void Sorted();
};

#endif // !INTERCHANGESORT