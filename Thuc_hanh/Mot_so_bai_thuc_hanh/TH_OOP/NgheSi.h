#pragma once
#include "Person.h"
class NgheSi :
    public Nguoi
{
    int namHanhNghe;
    string chuyeMon;
public:
    NgheSi();
    ~NgheSi();
    void input();
    void display();
};

