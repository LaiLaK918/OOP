#pragma once
#include <iostream>
#include "Point2D.h"

class TUGIAC
{
protected:
	Point2D point[4];
public:
	TUGIAC();
	~TUGIAC();
	virtual void input() = 0;
	virtual void display();
};

