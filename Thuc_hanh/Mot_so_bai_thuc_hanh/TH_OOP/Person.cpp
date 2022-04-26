#include "Person.h"

Nguoi::Nguoi()
{
	this->ten = "Noname";
	this->gioiTinh = 0;
	this->danToc = "Kinh";
	this->tonGiao = "Khong";
	this->queQuan = "HCM/VN";
	this->ngaySinh = "1/1/2000";
}

Nguoi::~Nguoi()
{

}

void Nguoi::input()
{
	cout << "\nNhap ten: ";
	getline(cin, this->ten);
	cout << "\nGioi tinh: ";
	cin >> this->gioiTinh;
	cout << "\nDan toc: ";
	cin.ignore();
	getline(cin, this->danToc);
	cout << "\nTon giao: ";
	getline(cin, this->tonGiao);
	cout << "\nQue quan: ";
	getline(cin, this->queQuan);
	cout << "\nNgay sinh: ";
	cin >> this->ngaySinh;
}

void Nguoi::display()
{
	cout << "Ten: " << this->ten;
	cout << "\nGioi tinh: " << (this->gioiTinh ? "Nu" : "Nam");
	cout << "\nDan toc: " << this->danToc;
	cout << "\nTon giao: " << this->tonGiao;
	cout << "\nQue quan: " << this->queQuan;
	cout << "\nNgay sinh: " << this->ngaySinh;
}
