#include "Point2D.h"

Point2D::Point2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

Point2D::~Point2D()
{

}

void Point2D::change(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Point2D::getX()
{
	return this->x;
}

float Point2D::getY()
{
	return this->y;
}

void Point2D::setX(float x)
{
	this->x = x;
}

void Point2D::setY(float y)
{
	this->y = y;
}

void Point2D::display()
{
	cout << "(" << this->x << ", " << this->y << ")";
}

void Point2D::input()
{
	cout << "Nhap diem: ";
	cin >> this->x >> this->y;
}
