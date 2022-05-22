#include "NVQL.h"

TienLuong::NVQL::NVQL() : NV()
{
	this->heSo = 0.f;
	this->thuong = 0;
}

TienLuong::NVQL::~NVQL()
{

}

void TienLuong::NVQL::nhap()
{
	NV::nhap();
	wcout << L"Nhập hệ số lương: ";
	cin >> this->heSo;
	wcout << L"Nhập tiền thưởng: ";
	cin >> this->thuong;
}

void TienLuong::NVQL::xuat()
{
	NV::xuat();
	wcout << "Hệ số lương: " << this->heSo << endl;
	wcout << "Tiền thưởng: " << this->thuong << endl;
}

int64_t TienLuong::NVQL::tinhLuong()
{
	return luongCoBan * heSo + thuong;
}

string TienLuong::NVQL::getType()
{
	return "NVQL";
}
