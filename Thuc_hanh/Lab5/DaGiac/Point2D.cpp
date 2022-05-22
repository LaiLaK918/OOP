#include "Point2D.h"

Point2D::Point2D(float _x, float _y)
{
	x = _x;
	y = _y;
}

Point2D::~Point2D()
{

}

void Point2D::Nhap()
{
	cout << "(x, y) = ";
	cin >> x >> y;
}

void Point2D::Xuat()
{
	printf("(%.2f, %.2f)", x, y);
}

float Point2D::distance(Point2D other)
{
	return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
}

void Point2D::TinhTien(Point2D other)
{
	x += other.x;
	y += other.y;
}

bool Point2D::operator==(Point2D other)
{
	return (x == other.x && y == other.y);
}

Point2D Point2D::operator-()
{
	return Point2D(-x, -y);
}

Point2D Point2D::operator-(Point2D other)
{
	return this->operator+(-other);
}

Point2D Point2D::operator+(Point2D other)
{
	return Point2D(x + other.x, y + other.y);
}
