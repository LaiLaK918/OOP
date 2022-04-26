#include "CongNhan.h"

CongNhan::CongNhan()
{
	this->luong = 1000;
	this->nganh = "ATTT";
	this->congTy = "VN";
	this->trinhDo = "TB";
}

CongNhan::~CongNhan()
{

}

void CongNhan::input()
{
	Nguoi::input();
	cout << "Luong: ";
	cin >> this->luong;
	cout << "Nganh: ";
	cin.ignore();
	getline(cin, this->nganh);
	cout << "Cong ty: ";
	getline(cin, this->congTy);
	cout << "Trinh do: ";
	getline(cin, this->trinhDo);
}

void CongNhan::display()
{
	Nguoi::display();
	cout << "\nLuong: " << this->luong;
	cout << "\nNganh: " << this->nganh;
	cout << "\nCong ty: " << this->congTy;
	cout << "\nTrinh do: " << this->trinhDo;
}
