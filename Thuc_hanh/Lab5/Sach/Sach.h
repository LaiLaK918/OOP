#pragma once
#include <iostream>
#include <string>
using namespace std;

class Sach
{
protected:
	string TieuDe;
	int Trang;
	string ISBM;
public:
	Sach();
	virtual ~Sach();
	virtual void Nhap();
	virtual void Xuat();
	virtual int TinhGia() = 0;
};

