#pragma once
#include "Robot.h"
class Carrier :
    public Robot
{
    float NLVanChuyen;
public:
    Carrier(float NL = 50.f);
    ~Carrier();
    void display(int S = 10);
    void input();
    float NangLuongTieuThu(float S);
    bool validProp();
    void setNL(float NL);
};

