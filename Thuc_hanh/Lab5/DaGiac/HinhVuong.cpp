#include "HinhVuong.h"

HinhVuong::HinhVuong() : HinhChuNhat()
{
}

HinhVuong::~HinhVuong()
{
	delete point;
}

bool HinhVuong::KiemTra()
{
	if (!(HinhChuNhat::KiemTra())) return false;
	if (point[0].distance(point[3]) == point[0].distance(point[1])) return true;
	return false;
}

void HinhVuong::Nhap()
{
	cout << "Hinh vuong\n";
	for (int i = 0; i < 4; i++) {
		point[i].Nhap();
	}
	if (!KiemTra()) Nhap();
}

void HinhVuong::Xuat()
{
	cout << "Hinh vuong: ";
	for (int i = 0; i < 4; i++) {
		point[i].Xuat();
		cout << ' ';
	}
}