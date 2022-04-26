#include "SinhVien.h"

SinhVien::SinhVien()
{
	this->GPA = 0;
	this->truong = "UIT";
	this->nganh = "ATTT";
}

SinhVien::~SinhVien()
{

}

void SinhVien::input()
{
	Nguoi::input();
	cout << "GPA: ";
	cin >> this->GPA;
	cout << "Truong: ";
	cin.ignore();
	getline(cin, this->truong);
	cout << "Nganh: ";
	getline(cin, this->nganh);
}

void SinhVien::display()
{
	Nguoi::display();
	cout << "\nGPA: " << this->GPA;
	cout << "\nTruong: " << this->truong;
	cout << "\nNganh: " << this->nganh;
}
