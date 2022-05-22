#include "HinhBinhHanh.h"

HinhBinhHanh::HinhBinhHanh() : TuGiac()
{
}

HinhBinhHanh::~HinhBinhHanh()
{
	delete point;
}

bool HinhBinhHanh::KiemTra()
{
	if (!(point[2] - point[3] == point[1] - point[0])) {
		return false;
	}
	if (!(point[3] - point[0] == point[2] - point[1])) {
		return false;
	}
	return true;
}

void HinhBinhHanh::Nhap()
{
	cout << "Hinh binh hanh\n";
	for (int i = 0; i < 4; i++) {
		point[i].Nhap();
	}
	if (!KiemTra()) Nhap();
}

void HinhBinhHanh::Xuat()
{
	cout << "Hinh binh hanh: ";
	for (int i = 0; i < 4; i++) {
		point[i].Xuat();
		cout << ' ';
	}
}