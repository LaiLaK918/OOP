#pragma once
#include <iostream>
using namespace std;

class CTimeSpan
{
	int span;
public:
	CTimeSpan(int span = 0);
	~CTimeSpan();
	friend ostream& operator << (ostream&, CTimeSpan);
	CTimeSpan operator+(CTimeSpan);
	CTimeSpan operator-(CTimeSpan);
	bool operator == (CTimeSpan);
	bool operator != (CTimeSpan);
	bool operator > (CTimeSpan);
	bool operator >= (CTimeSpan);
	bool operator < (CTimeSpan);
	bool operator <= (CTimeSpan);
};