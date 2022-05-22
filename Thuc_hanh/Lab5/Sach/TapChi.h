#pragma once
#include "Sach.h"
class TapChi :
    public Sach
{
    int Ngay;
    int So;
public:
    TapChi();
    ~TapChi();
    void Nhap();
    void Xuat();
    int TinhGia();
};

