#include "HinhTron.h"

HinhTron::HinhTron()
{
	this->a = 0;
	this->b = 0;
}

HinhTron::~HinhTron()
{

}

void HinhTron::display()
{
	cout << "Hinh tron: r = " << this->a << ". Tam: ";
	tam.display();
}

void HinhTron::input()
{
	cout << "Nhap ban kinh: ";
	cin >> this->a;
	this->b = this->a;
}
