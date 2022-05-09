#include "NV.h"

TienLuong::NV::NV()
{
	this->ten = L"";
	this->ngaySinh = L"";
	this->luongCoBan = 0;
}

TienLuong::NV::~NV()
{

}

void TienLuong::NV::nhap()
{
	wcout << L"Nhập tên: ";
	getline(wcin, ten);
	wcout << L"Nhập ngày sinh: ";
	wcin >> ngaySinh;
	wcout << L"Nhập lương cơ bản: ";
	cin >> luongCoBan;
}

void TienLuong::NV::xuat()
{
	wcout << L"Tên: " << this->ten << endl;
	wcout << L"Ngày sinh: " << this->ngaySinh << endl;
	wcout << L"Lương cơ bản: " << this->luongCoBan << endl;
}

wstring TienLuong::NV::getTen()
{
	return this->ten;
}
