#pragma once
#include "Point2D.h"
#include <iostream>
using namespace std;

class Elipse
{
protected:
	Point2D tam;
	float a; // nua tru lon
	float b; // nua tru nho
public:
	Elipse();
	~Elipse();
	virtual void input();
	virtual void display();
	virtual float calArea();
};