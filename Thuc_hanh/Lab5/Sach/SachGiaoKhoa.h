#pragma once
#include "Sach.h"
class SachGiaoKhoa :
    public Sach
{
    int Chuong;
    string MonHoc;
public:
    SachGiaoKhoa();
    ~SachGiaoKhoa();
    void Nhap();
    void Xuat();
    int TinhGia();
};

