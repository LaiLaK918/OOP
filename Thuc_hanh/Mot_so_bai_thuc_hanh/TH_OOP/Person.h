#pragma once
#include <iostream>
#include <string>
using namespace std;

class Nguoi
{
protected:
	string ten;
	bool gioiTinh; // 0 nam, 1 nu
	string danToc;
	string tonGiao;
	string queQuan;
	string ngaySinh;
public:
	Nguoi();
	virtual ~Nguoi();
	virtual void input();
	virtual void display();
};

