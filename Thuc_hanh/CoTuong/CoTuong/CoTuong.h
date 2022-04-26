#ifndef COTUONG_H
#define COTUONG_H

#pragma once
#include "QuanCo.h"
#include "externLib.h"
using ATCL2021::QuanCo;

_ATCL2021_START
class CoTuong
{
    QuanCo* qc[32];
public:
    CoTuong();
    ~CoTuong();
};

_ATCL2021_END
#endif // !COTUONG_H
