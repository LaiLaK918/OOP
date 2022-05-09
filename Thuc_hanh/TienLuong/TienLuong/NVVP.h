#pragma once
#include "NV.h"

namespace TienLuong {

    class NVVP :
        public NV
    {
        int soNgayLamViec;
        long troCap;
    public:
        NVVP();
        ~NVVP();
        void nhap();
        void xuat();
        int64_t tinhLuong();
        string getType();
    };

}