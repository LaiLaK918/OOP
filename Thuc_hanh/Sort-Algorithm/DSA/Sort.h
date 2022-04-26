#pragma once

#ifndef SORT

#define SORT

#include <iostream>
#include <fstream>
using namespace std;	

class Sort
{
protected:
	int* arr;
	int n;
public:
	Sort();

	Sort(int);

	~Sort();

	virtual void Sorted() = 0;

	virtual void print();

	inline int getN();

	inline virtual void input(std::fstream&);

	inline bool ascending(const int&, const int&);

	inline bool decending(const int&, const int&);

	virtual void inputRan();
};

#endif // !SORT