#ifndef MA_H
#define MA_H

#pragma once
#include "ATCL2021.h"

_ATCL2021_START
class Ma :
    public QuanCo
{
public:
    Ma();
    Ma(Point, bool);
    ~Ma();
    void diChuyen();
    void getLoai();
};

_ATCL2021_END
#endif // !MA_H