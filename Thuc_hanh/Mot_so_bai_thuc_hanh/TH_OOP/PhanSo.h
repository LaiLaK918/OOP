#pragma once
#include <iostream>
using namespace std;

class PhanSo
{
	int tu;
	int mau;
public:
	PhanSo(int tu = 0, int mau = 1);
	~PhanSo();
	int _gcd(int, int);
	void rut_gon();
	friend ostream& operator << (ostream&, PhanSo);
	friend istream& operator >> (istream&, PhanSo&);
	PhanSo operator+(PhanSo);
	PhanSo operator-(PhanSo);
	PhanSo operator*(PhanSo);
	PhanSo operator/(PhanSo);
	bool operator == (PhanSo);
	bool operator != (PhanSo);
	bool operator > (PhanSo);
	bool operator >= (PhanSo);
	bool operator < (PhanSo);
	bool operator <= (PhanSo);
};

