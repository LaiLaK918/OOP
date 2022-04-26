#ifndef QUANCO_H
#define QUANCO_H

#pragma once
#include "Point.h"
using ATCL2021::Point;

_ATCL2021_START
class QuanCo
{
protected:
	Point point;
	bool color; // 0 ~ den, 1 ~ trang
public:
	QuanCo();
	QuanCo(Point, bool);
	virtual void diChuyen() = 0;
	virtual void getLoai() = 0;
	~QuanCo();
};

_ATCL2021_END
#endif // !QUANCO_H