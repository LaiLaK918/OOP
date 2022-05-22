#include "SachGiaoKhoa.h"

SachGiaoKhoa::SachGiaoKhoa()
{

}

SachGiaoKhoa::~SachGiaoKhoa()
{

}

void SachGiaoKhoa::Nhap()
{
	Sach::Nhap();
	cout << "Chuong: ";
	cin >> Chuong;
	cin.ignore();
	cout << "Mon hoc: ";
	getline(cin, MonHoc);
}

void SachGiaoKhoa::Xuat()
{
	Sach::Xuat();
	cout << "Chuong: " << Chuong << endl;
	cout << "Mon hoc: " << MonHoc << endl;
}

int SachGiaoKhoa::TinhGia()
{
	return 5000 * Trang;
}
