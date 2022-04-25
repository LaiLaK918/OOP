#pragma once
#include "Robot.h"
class Pedion :
    public Robot
{
    float linhHoat;
public:
    Pedion(float linhHoat = 1.f);
    ~Pedion();
    void input();
    void display(int S = 10);
    float NangLuongTieuThu(float S);
    bool validProp();
    void setLH(float LH);
};

