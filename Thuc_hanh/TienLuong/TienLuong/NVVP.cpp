#include "NVVP.h"

TienLuong::NVVP::NVVP() : NV()
{
	this->soNgayLamViec = 0;
	this->troCap = 0;
}

TienLuong::NVVP::~NVVP()
{

}

void TienLuong::NVVP::nhap()
{
	NV::nhap();
	wcout << L"Nhập số ngày làm việc: ";
	cin >> this->soNgayLamViec;
	wcout << L"Nhập tiền trợ cấp: ";
	cin >> this->troCap;
}

void TienLuong::NVVP::xuat()
{
	NV::xuat();
	wcout << L"Số ngày làm việc: " << this->soNgayLamViec << endl;
	wcout << L"Tiền trợ cấp: " << this->troCap << endl;
}

int64_t TienLuong::NVVP::tinhLuong()
{
	return luongCoBan * soNgayLamViec + troCap;
}

string TienLuong::NVVP::getType()
{
	return "NVVP";
}
