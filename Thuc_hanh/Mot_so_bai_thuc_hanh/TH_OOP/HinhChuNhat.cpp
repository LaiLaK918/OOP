#include "HinhChuNhat.h"

HinhChuNhat::HinhChuNhat()
{
	dai = 0.f;
	rong = dai;
}

HinhChuNhat::~HinhChuNhat()
{

}

void HinhChuNhat::input()
{
	cout << "Hinh chu nhat: ";
	cout << "\nDiem A: ";
	point[0].input();
	cout << "\nDai: ";
	cin >> dai;
	cout << "Rong: ";
	cin >> rong;
	point[1].setX(point[0].getX()+dai);
	point[1].setY(point[1].getY());
	point[2].setX(point[1].getX());
	point[2].setY(point[1].getY() + rong);
	point[3].setX(point[0].getX());
	point[3].setY(point[0].getY() + rong);
}
