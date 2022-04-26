#pragma once
#include <iostream>
#include <string>
using namespace std;

class NhanVien
{
protected:
	string hoten;
	string ngaysinh;
public:
	NhanVien(string hoten = "", string ngaysinh = "");
	virtual ~NhanVien();
	virtual int tinhLuong() = 0;
	virtual void display();
	virtual void input();
	void setHoten(string hoten);
	void setNgaysinh(string ngaysinh);
	string getHoten();
	string getNgaySinh();
};