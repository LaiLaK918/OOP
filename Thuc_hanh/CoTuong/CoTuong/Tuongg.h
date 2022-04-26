#ifndef TUONGG_H
#define TUONGG_H

#pragma once
#include "ATCL2021.h"

_ATCL2021_START
class Tuongg :
    public QuanCo
{
public:
    Tuongg();
    Tuongg(Point, bool);
    ~Tuongg();
    void diChuyen();
    void getLoai();
};

_ATCL2021_END
#endif // !TUONGG_H