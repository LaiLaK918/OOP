#ifndef TOT_H
#define TOT_H

#pragma once
#include "ATCL2021.h"

_ATCL2021_START
class Tot :
    public QuanCo
{
public:
    Tot();
    Tot(Point, bool);
    ~Tot();
    void diChuyen();
    void getLoai();

};

_ATCL2021_END
#endif // !TOT_H