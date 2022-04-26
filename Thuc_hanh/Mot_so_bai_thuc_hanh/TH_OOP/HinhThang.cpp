#include "HinhThang.h"

HinhThang::HinhThang()
{

}

HinhThang::~HinhThang()
{

}

void HinhThang::input()
{
	cout << "Nhap hinh thang: ";
	cout << "\nDiem A: ";
	point[0].input();
	cout << "Diem B: (" << this->point[0].getX() << ", ";
	float y;
	cin >> y;
	this->point[1].setX(this->point[0].getX());
	this->point[1].setY(y);
	cout << "Diem C: ";
	this->point[2].input();
	cout << "Diem D: (" << this->point[2].getX() << ", ";
	cin >> y;
	this->point[3].setX(this->point[2].getX());
	this->point[3].setY(y);
}
