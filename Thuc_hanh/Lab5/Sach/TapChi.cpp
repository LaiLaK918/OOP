#include "TapChi.h"

TapChi::TapChi()
{

}

TapChi::~TapChi()
{

}

void TapChi::Nhap()
{
	Sach::Nhap();
	cout << "Ngay: ";
	cin >> Ngay;
	cout << "So: ";
	cin >> So;
}

void TapChi::Xuat()
{
	Sach::Xuat();
	cout << "Ngay: " << Ngay << endl;
	cout << "So: " << So << endl;

}

int TapChi::TinhGia()
{
	return 7000 * Trang;
}
