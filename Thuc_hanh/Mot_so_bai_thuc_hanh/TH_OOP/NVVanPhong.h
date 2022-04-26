#pragma once
#include "NhanVien.h"
class NVVanPhong :
    public NhanVien
{
    int ngayLamViec;
public:
    NVVanPhong(string hoten = "", string ngaysinh = "", int ngayLamViec = 0);
    ~NVVanPhong();
    void display();
    int tinhLuong();
    void setNLV(int ngayLamViec);
    int getNLV();
    void input();
};

