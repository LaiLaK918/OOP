#ifndef PHAO_H
#define PHAO_H

#pragma once
#include "ATCL2021.h"

_ATCL2021_START
class Phao :
    public QuanCo
{
public:
    Phao();
    Phao(Point, bool);
    ~Phao();
    void diChuyen();
    void getLoai();
};

_ATCL2021_END
#endif // !PHAO_H