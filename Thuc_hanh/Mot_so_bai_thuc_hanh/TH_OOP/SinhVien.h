#pragma once
#include "Person.h"
class SinhVien :
    public Nguoi
{
    float GPA;
    string truong;
    string nganh;
public:
    SinhVien();
    ~SinhVien();
    void input();
    void display();
};