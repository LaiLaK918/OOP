#include "TieuThuyet.h"

TieuThuyet::TieuThuyet()
{

}

TieuThuyet::~TieuThuyet()
{

}

void TieuThuyet::Nhap()
{
	Sach::Nhap();
	cout << "Chuong: ";
	cin >> Chuong;
	cout << "The loai: ";
	cin.ignore();
	getline(cin, TheLoai);
	cout << "Tac gia: ";
	getline(cin, TacGia);
}

void TieuThuyet::Xuat()
{
	Sach::Xuat();
	cout << "Chuong: " << Chuong << endl;
	cout << "The loai: " << TheLoai << endl;
	cout << "Tac gia: " << TacGia << endl;
}

int TieuThuyet::TinhGia()
{
	return 12000 * Trang;
}
