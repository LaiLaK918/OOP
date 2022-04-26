#include "NVVanPhong.h"

NVVanPhong::NVVanPhong(string hoten, string ngaysinh, int ngayLamViec) : NhanVien(hoten, ngaysinh)
{
	this->ngayLamViec = ngayLamViec;
	cout << "Generated NVVanPhong\n";
}

NVVanPhong::~NVVanPhong()
{
	cout << "Deleted NVVP\n";
}

void NVVanPhong::display()
{
	NhanVien::display();
	cout << "\nLuong: " << this->tinhLuong();
}

int NVVanPhong::tinhLuong()
{
	return this->ngayLamViec*100000;
}

void NVVanPhong::setNLV(int ngayLamViec)
{
	this->ngayLamViec = ngayLamViec;
}

int NVVanPhong::getNLV()
{
	return this->ngayLamViec;
}

void NVVanPhong::input()
{
	NhanVien::input();
	cout << "Ngay lam viec: ";
	cin >> ngayLamViec;
}
