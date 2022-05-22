#include "HinhChuNhat.h"

HinhChuNhat::HinhChuNhat() : HinhBinhHanh()
{
}

HinhChuNhat::~HinhChuNhat()
{
	delete point;
}

bool HinhChuNhat::KiemTra()
{
	if (!HinhBinhHanh::KiemTra()) return false;
	Point2D a = point[3] - point[0];
	Point2D b = point[1] - point[0];
	if (a.x * b.x + a.y * b.y == 0)  return true;
	return false;
}

void HinhChuNhat::Nhap()
{
	cout << "Hinh chu nhat\n";
	for (int i = 0; i < 4; i++) {
		point[i].Nhap();
	}
	if (!KiemTra()) Nhap();
}

void HinhChuNhat::Xuat()
{
	cout << "Hinh chu nhat: ";
	for (int i = 0; i < 4; i++) {
		point[i].Xuat();
		cout << ' ';
	}
}