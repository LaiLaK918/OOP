#pragma once
#include "DaGiac.h"
class TuGiac :
    public DaGiac
{
public:
    TuGiac(int n = 4);
    virtual ~TuGiac();
    void Nhap();
    void Xuat();
    void TinhTien(Point2D other);
    void TinhTien(float x, float y);
};

