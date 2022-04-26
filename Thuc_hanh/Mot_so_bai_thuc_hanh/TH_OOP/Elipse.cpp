#include "Elipse.h"

Elipse::Elipse()
{
	this->a = 0.f;
	this->b = 0.f;
	tam.change(0, 0);
}

Elipse::~Elipse()
{

}

void Elipse::input()
{
	cout << "Nhap truc lon: ";
	cin >> this->a;
	cout << "Nhap truc nho: ";
	cin >> this->b;
}

void Elipse::display()
{
	cout << "Elipse: x^2/" << a * a << " + " << "y^2/" << b * b << " = 1. Tam: ";
	tam.display();
}

float Elipse::calArea()
{
	return 3.14f*a*b;
}
