#pragma once

#ifndef SORT

#define SORT

#include <iostream>
#include <fstream>

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

	void print();

	inline int getN();

	inline void _swap(int&, int&);

	inline void nhapMang(std::fstream&);

	inline bool ascending(const int&, const int&);

	inline bool decending(const int&, const int&);
};

#endif // !SORT