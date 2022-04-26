#include "Point.h"
using namespace ATCL2021;

Point::Point(int _x, int _y) {
	x = _x;
	y = _y;
}

void Point::setX(int _x) {
	x = _x;
}

void Point::setY(int _y) {
	y = _y;
}

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}

Point::~Point() {
	
}