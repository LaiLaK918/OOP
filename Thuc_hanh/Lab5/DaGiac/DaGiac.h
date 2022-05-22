#pragma once
#include "Point2D.h"

class DaGiac
{
protected:
	Point2D* point;
	int n;
public:
	DaGiac();
	virtual ~DaGiac();
	virtual void Nhap() = 0;
	virtual void Xuat() = 0;
	virtual void TinhTien(Point2D other) = 0;
	virtual void TinhTien(float x, float y) = 0;
	virtual bool KiemTra();
};