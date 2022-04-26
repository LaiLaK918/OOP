#pragma once
#include "Person.h"
class CongNhan :
    public Nguoi
{
    int luong;
    string nganh;
    string congTy;
    string trinhDo;
public:
    CongNhan();
    ~CongNhan();
    void input();
    void display();
};