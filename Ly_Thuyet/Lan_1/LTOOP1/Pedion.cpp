#include "Pedion.h"

Pedion::Pedion(float linhHoat)
{
	this->trongLuong = 20;
	this->linhHoat = linhHoat;
}

Pedion::~Pedion()
{

}

void Pedion::input()
{
	wcout << endl << BIEN << L"Nhập thông tin robot loại Pedion" << BIEN;
	wcout << L"\nĐã biết thông tin - Trọng lượng: " << this->trongLuong;
	wcout << L"\nNhập độ linh hoạt: ";
	wcin >> this->linhHoat;
	if (!this->validProp()) {
		wcout << L"\nThông tin không hợp lệ!";
		this->input();
	}
	else wcout << BIEN_END << L"Kết thúc" << BIEN_END;
}

void Pedion::display(int S)
{
	wcout << endl << BIEN << L"Robot loại Pedion" << BIEN;
	Robot::display();
	wcout << L"\nĐộ linh hoạt: " << this->linhHoat;
	wcout << L"\nChức năng: xây dựng.";
	wcout << L"\nNăng lượng tiêu thụ: " << this->NangLuongTieuThu(S);
}

float Pedion::NangLuongTieuThu(float S)
{
	return Robot::NangLuongTieuThu(S) + (this->linhHoat + 1) * S / 2;
}

bool Pedion::validProp()
{
	return (this->linhHoat >= 1 && this->linhHoat <= 5);
}

void Pedion::setLH(float LH)
{
	this->linhHoat = LH;
}
