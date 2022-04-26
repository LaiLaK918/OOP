#ifndef POINT_H
#define POINT_H


#pragma once
#include "externLib.h"
_ATCL2021_START

class Point
{
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0);
	void setX(int);
	void setY(int);
	int getX();
	int getY();
	~Point();
};

_ATCL2021_END
#endif // !POINT_H