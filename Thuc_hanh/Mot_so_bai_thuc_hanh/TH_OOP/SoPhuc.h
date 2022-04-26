#pragma once
#include<iostream>
using namespace std;

class SoPhuc
{
	float thuc;
	float ao;
public:
	SoPhuc(float _thuc = 0, float _ao = 0);
	~SoPhuc();
	void nhap();
	void xuat();
	float abs(bool mu2 = false); //Dinh gia tri
	void setThuc(float);
	void setAo(float);
	float getThuc();
	float getAo();
	SoPhuc cong(SoPhuc);
	SoPhuc tru(SoPhuc);
	SoPhuc nhan(SoPhuc);
	SoPhuc chia(SoPhuc);
	friend ostream& operator << (ostream&, SoPhuc);
	friend istream& operator >> (istream&, SoPhuc&);
	SoPhuc operator + (SoPhuc);
	SoPhuc operator - (SoPhuc);
	SoPhuc operator * (SoPhuc);
	SoPhuc operator / (SoPhuc);
	bool operator == (SoPhuc);
	bool operator != (SoPhuc);
	bool operator > (SoPhuc);
	bool operator >= (SoPhuc);
	bool operator < (SoPhuc);
	bool operator <= (SoPhuc);
};