#pragma once
#include "NhanVien.h"
class NVSanXuat :
	public NhanVien
{
	int luongCanBan;
	int soSanPhan;
public:
	NVSanXuat(string hoten = "", string ngaysinh = "", int luongCanBan = 0, int soSanPham = 0);
	~NVSanXuat();
	void setLuongCanBan(int luong);
	int getLuongCanBan();
	int tinhLuong();
	void display();
	void input();
};

