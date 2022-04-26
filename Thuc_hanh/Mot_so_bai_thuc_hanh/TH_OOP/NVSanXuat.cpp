#include "NVSanXuat.h"

NVSanXuat::NVSanXuat(string hoten, string ngaysinh, int luongCanBan, int soSanPham) : NhanVien(hoten, ngaysinh)
{
	this->luongCanBan = luongCanBan;
	this->soSanPhan = soSanPham;
	cout << "Generated NVSanXuat\n";
}

NVSanXuat::~NVSanXuat()
{
	cout << "Deleted NVSX\n";
}

void NVSanXuat::setLuongCanBan(int luong)
{
	this->luongCanBan = luong;
}

int NVSanXuat::getLuongCanBan()
{
	return this->luongCanBan;
}

int NVSanXuat::tinhLuong()
{
	return this->luongCanBan + this->soSanPhan*5000;
}

void NVSanXuat::display()
{
	NhanVien::display();
	cout << "\nLuong: " << this->tinhLuong();
}

void NVSanXuat::input()
{
	NhanVien::input();
	cout << "Nhap luong can ban: ";
	cin >> this->luongCanBan;
	cout << "Nhap so san pham: ";
	cin >> this->soSanPhan;
}
