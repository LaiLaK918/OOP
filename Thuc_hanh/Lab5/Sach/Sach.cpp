#include "Sach.h"

Sach::Sach()
{

}

Sach::~Sach()
{

}

void Sach::Nhap()
{
	cout << "Tieu de: ";
	cin.ignore();
	getline(cin, TieuDe);
	cout << "Trang: ";
	cin >> Trang;
	cout << "ISBM: ";
	cin.ignore();
	getline(cin, ISBM);
}

void Sach::Xuat()
{
	cout << "Tieu de: " << TieuDe << endl;
	cout << "Trang: " << Trang << endl;
	cout << "ISBM: " << ISBM << endl;
}
