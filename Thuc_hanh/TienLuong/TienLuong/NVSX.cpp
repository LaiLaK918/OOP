#include "NVSX.h"

TienLuong::NVSX::NVSX() : NV()
{
	this->soSanPham = 0;
}

TienLuong::NVSX::~NVSX()
{

}

void TienLuong::NVSX::nhap()
{
	NV::nhap();
	wcout << L"Nhập số sán phẩm: ";
	cin >> this->soSanPham;
}

void TienLuong::NVSX::xuat()
{
	NV::xuat();
	wcout << L"Số sản phẩm" << this->soSanPham << endl;
}

int64_t TienLuong::NVSX::tinhLuong()
{
	return luongCoBan + soSanPham * 20000ll;
}

string TienLuong::NVSX::getType()
{
	return "NVSX";
}
