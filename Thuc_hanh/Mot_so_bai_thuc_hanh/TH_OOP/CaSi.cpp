#include "CaSi.h"

CaSi::CaSi()
{
	this->soBaiHat = 0;
	this->view = 0;
}

CaSi::~CaSi()
{

}

void CaSi::input()
{
	Nguoi::input();
	cout << "So bai hat: ";
	cin >> this->soBaiHat;
	cout << "Views: ";
	cin >> this->view;
}

void CaSi::display()
{
	Nguoi::display();
	cout << "\nSo bai hat: " << this->soBaiHat;
	cout << "\nViews: " << this->view;
}
