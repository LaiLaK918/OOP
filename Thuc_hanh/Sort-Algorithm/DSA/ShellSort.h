#pragma once

#ifndef SHELLSORT

#define SHELLSORT

#include "Sort.h"
class ShellSort :
    public Sort
{
public:
    ShellSort();
    ShellSort(int);
    ~ShellSort();
    void Sorted();
};

#endif // !SHELLSORT