#include "HocSinh.h"

HocSinh::HocSinh()
{
	this->GPA = 0;
	this->truong = "THPT";
	this->hocLuc = "Gioi";
	this->hanhKiem = "Tot";
}

HocSinh::~HocSinh()
{

}

void HocSinh::input()
{
	Nguoi::input();
	cout << "GPA: ";
	cin >> this->GPA;
	cout << "Truong: ";
	cin.ignore();
	getline(cin, this->truong);
	cout << "Hoc luc: ";
	getline(cin, this->hocLuc);
	cout << "Hanh kiem: ";
	getline(cin, this->hanhKiem);
}

void HocSinh::display()
{
	Nguoi::display();
	cout << "\nGPA: " << this->GPA;
	cout << "\nTruong: " << this->GPA;
	cout << "\nHoc luc: " << this->hocLuc;
	cout << "\nHanh kiem: " << this->hanhKiem;
}
