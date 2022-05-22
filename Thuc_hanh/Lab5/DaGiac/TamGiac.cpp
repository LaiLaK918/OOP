#include "TamGiac.h"

TamGiac::TamGiac(int n)
{
	point = new Point2D();
}

TamGiac::~TamGiac()
{
	delete point;
}

void TamGiac::Nhap()
{
	cout << "Tam giac\n";
	for (int i = 0; i < 3; i++) {
		point[i].Nhap();
	}
}

void TamGiac::Xuat()
{
	cout << "Tam giac: ";
	for (int i = 0; i < 3; i++) {
		point[i].Xuat();
		cout << ' ';
	}
}

void TamGiac::TinhTien(Point2D other)
{
	for (int i = 0; i < 3; i++) {
		point[i].TinhTien(other);
	}
}

void TamGiac::TinhTien(float x, float y)
{
	TinhTien(Point2D(x, y));
}
