#ifndef SI_H
#define SI_H

#pragma once
#include "ATCL2021.h"

_ATCL2021_START
class Si :
    public QuanCo
{
public:
    Si();
    Si(Point, bool);
    ~Si();
    void diChuyen();
    void getLoai();

};

_ATCL2021_END
#endif // !SI_H