#pragma once
#include "Person.h"
class HocSinh :
    public Nguoi
{
    float GPA;
    string truong;
    string hocLuc;
    string hanhKiem;
public:
    HocSinh();
    ~HocSinh();
    void input();
    void display();
};

