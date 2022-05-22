#include "TuGiac.h"

TuGiac::TuGiac(int n)
{
	point = new Point2D();
}

TuGiac::~TuGiac()
{
	delete point;
}

void TuGiac::Nhap()
{
	cout << "Tu giac\n";
	for (int i = 0; i < 4; i++) {
		point[i].Nhap();
	}
}

void TuGiac::Xuat()
{
	cout << "Tu giac: ";
	for (int i = 0; i < 4; i++) {
		point[i].Xuat();
		cout << ' ';
	}
}

void TuGiac::TinhTien(Point2D other)
{
	for (int i = 0; i < 4; i++) {
		point[i].TinhTien(other);
	}
}

void TuGiac::TinhTien(float x, float y)
{
	TinhTien(Point2D(x, y));
}
