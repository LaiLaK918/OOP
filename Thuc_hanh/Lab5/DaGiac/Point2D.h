#pragma once
#include <math.h>
#include <iostream>
using namespace std;

class Point2D
{
public:
	float x, y;
	// constructor
	Point2D(float x = 0, float y = 0);
	~Point2D();
	void Nhap();
	void Xuat();
	float distance(Point2D other);
	void TinhTien(Point2D other);
	bool operator ==(Point2D other);
	Point2D operator-();
	Point2D operator-(Point2D other);
	Point2D operator+(Point2D other);
};

