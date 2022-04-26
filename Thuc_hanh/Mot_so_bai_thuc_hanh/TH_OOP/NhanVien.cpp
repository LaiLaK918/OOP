#include "NhanVien.h"

NhanVien::NhanVien(string hoten, string ngaysinh)
{
	this->hoten = hoten;
	this->ngaysinh = ngaysinh;
	cout << "Generated NhanVien\n";
}

NhanVien::~NhanVien()
{
	cout << "Deleted NV\n";
}

void NhanVien::setHoten(string hoten)
{
	this->hoten = hoten;
}

void NhanVien::setNgaysinh(string ngaysinh)
{
	this->ngaysinh = ngaysinh;
}

string NhanVien::getHoten()
{
	return this->hoten;
}

string NhanVien::getNgaySinh()
{
	return this->ngaysinh;
}

void NhanVien::display()
{
	cout << "\nHo ten: " << this->hoten;
	cout << "\nNgay sinh: " << this->ngaysinh;
}

void NhanVien::input()
{
	cout << "Nhap ho ten: ";
	cin.ignore();
	getline(cin, this->hoten);
	cout << "Nhap ngay sinh: ";
	getline(cin, this->ngaysinh);
}
