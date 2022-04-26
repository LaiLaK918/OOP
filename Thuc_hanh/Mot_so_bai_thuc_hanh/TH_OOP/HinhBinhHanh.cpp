#include "HinhBinhHanh.h"

HinhBinhHanh::HinhBinhHanh()
{

}

HinhBinhHanh::~HinhBinhHanh()
{

}

void HinhBinhHanh::input()
{
	cout << "\nHinh binh hanh: ";
	cout << "\nDiem A: ";
	this->point[0].input();
	cout << "\nDiem B: x = " << this->point[0].getX() << ", y = ";
	int y;
	cin >> y;
	this->point[1].setX(this->point[0].getX());
	this->point[1].setY(y);
	cout << "\nDiem C: ";
	this->point[2].input();
	this->point[3].setX(point[0].getX() - point[1].getX() + point[2].getX());
	this->point[3].setY(point[0].getY() - point[1].getY() + point[2].getY());
}
