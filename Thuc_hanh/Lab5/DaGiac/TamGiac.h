#pragma once
#include "DaGiac.h"
class TamGiac :
    public DaGiac
{
public:
    TamGiac(int n = 3);
    ~TamGiac();
    void Nhap();
    void Xuat();
    void TinhTien(Point2D other);
    void TinhTien(float x, float y);
};

