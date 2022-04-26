#pragma once
#include <iostream>
using namespace std;

class Point2D
{
	float x;
	float y;
public:
	Point2D(float x = 0.f, float y= 0.f);
	~Point2D();
	void change(float x, float y);
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	void display();
	void input();
};

