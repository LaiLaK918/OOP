#pragma once
#include "Sach.h"
class TieuThuyet :
    public Sach
{
    int Chuong;
    string TheLoai;
    string TacGia;
public:
    TieuThuyet();
    ~TieuThuyet();
    void Nhap();
    void Xuat();
    int TinhGia();
};

