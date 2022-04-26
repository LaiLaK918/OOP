#include "NgheSi.h"

NgheSi::NgheSi()
{
	this->namHanhNghe = 2;
	this->chuyeMon = "Dan gian";
}

NgheSi::~NgheSi()
{

}

void NgheSi::input()
{
	Nguoi::input();
	cout << "Nam hanh nghe: ";
	cin >> this->namHanhNghe;
	cout << "Chuyen mon: ";
	cin.ignore();
	getline(cin, this->chuyeMon);
}

void NgheSi::display()
{	
	Nguoi::display();
	cout << "\nNam hanh nghe: " << this->namHanhNghe;
	cout << "\nChuyen mon: " << this->chuyeMon;
}
