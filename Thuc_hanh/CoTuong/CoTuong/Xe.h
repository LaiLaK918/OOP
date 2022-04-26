
#ifndef XE_H
#define XE_H

#pragma once
#include "ATCL2021.h"

_ATCL2021_START
class Xe :
    public QuanCo
{
public:
    Xe();
    Xe(Point, bool);
    ~Xe();
    void diChuyen();
    void getLoai();

};

_ATCL2021_END
#endif // !XE_H