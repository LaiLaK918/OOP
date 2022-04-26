#pragma once
#include "Person.h"


class CaSi :
    public Nguoi
{
    int soBaiHat;
    int view;
public:
    CaSi();
    ~CaSi();
    void input();
    void display();
};

