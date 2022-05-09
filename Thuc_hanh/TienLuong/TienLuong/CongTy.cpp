#include "CongTy.h"

TienLuong::CongTy::CongTy(int _size)
{
    if (_size) {
        nv = new NV * [_size];
    }
    else {
        nv = NULL;
    }
    this->size = _size;
}

TienLuong::CongTy::~CongTy()
{
    for (int i = 0; i < size; i++) {
        delete nv[i];
    }
    if (nv) delete[] nv;
}

void TienLuong::CongTy::nhap()
{
    autoFree(nv);
    wcout << L"Nhập tổng số lượng công nhân: ";
    cin >> this->size;
    nv = new NV * [size];
    wcout << L"Nhập số nhân viên quản lí: ";
    int temp, i;
    cin >> temp;
    for (i = 0; i < temp; i++) {
        nv[i] = new NVQL();
        nv[i]->nhap();
    }
    wcout << L"Nhập số nhân viên sản xuất: ";
    cin >> temp;
    temp += i;
    for (; i < temp; i++) {
        nv[i] = new NVSX();
        nv[i]->nhap();
    }
    wcout << L"Nhập số nhân viên văn phòng: ";
    cin >> temp;
    temp += i;
    for (; i < temp; i++) {
        nv[i] = new NVVP();
        nv[i]->nhap();
    }
}

void TienLuong::CongTy::xuat()
{
    for (int i = 0; i < size; i++) {
        nv[i]->xuat();
    }
}

int64_t TienLuong::CongTy::tongLuong()
{
    int64_t tong = 0;
    for (int i = 0; i < size; i++) {
        tong += nv[i]->tinhLuong();
    }
    return tong;
}

TienLuong::NV* TienLuong::CongTy::timKiem(wstring ten)
{
    for (int i = 0; i < size; i++) {
        if (nv[i]->getTen() == ten) return nv[i];
    }
    return nullptr;
}

void TienLuong::CongTy::autoFree(NV** _nv)
{
    if (size) {
        for (int i = 0; i < size; i++) {
            delete _nv[i];
        }
        delete[] nv;
    }
}
