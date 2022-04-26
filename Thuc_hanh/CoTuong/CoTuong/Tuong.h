#ifndef TUONG_H
#define TUONG_H

#pragma once
#include "ATCL2021.h"

_ATCL2021_START
class Tuong :
    public QuanCo
{
public:
    Tuong();
    Tuong(Point, bool);
    ~Tuong();
    void diChuyen();
    void getLoai();
};

_ATCL2021_END
#endif // !TUONG_H