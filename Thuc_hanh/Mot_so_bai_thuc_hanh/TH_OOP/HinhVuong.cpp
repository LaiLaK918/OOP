#include "HinhVuong.h"

HinhVuong::HinhVuong()
{
	canh = 0.f;
}

HinhVuong::~HinhVuong()
{

}

void HinhVuong::input()
{
	cout << "Hinh vuong: ";
	cout << "\nDiem A: ";
	point[0].input();
	point[1].setX(point[0].getX() + canh);
	point[1].setY(point[1].getY());
	point[2].setX(point[1].getX());
	point[2].setY(point[1].getY() + canh);
	point[3].setX(point[0].getX());
	point[3].setY(point[0].getY() + canh);
}
