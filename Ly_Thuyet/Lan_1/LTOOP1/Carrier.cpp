#include "Carrier.h"

Carrier::Carrier(float NL)
{
	this->trongLuong = 30;
	this->NLVanChuyen = NL;
}

Carrier::~Carrier()
{

}

void Carrier::display(int S)
{
	wcout << endl << BIEN << L"Robot loại Carrier" << BIEN;
	Robot::display();
	wcout << L"\nKho năng lượng vận chuyển: " << this->NLVanChuyen;
	wcout << L"\nChức năng: mang năng lượng tiếp tế.";
	wcout << L"\nNăng lượng tiêu thụ: " << this->NangLuongTieuThu(S);
}

void Carrier::input()
{
	wcout << endl << BIEN << L"Nhập thông tin robot loại Carrier" << BIEN;
	wcout << L"\nĐã biết thông tin - Trọng lượng: " << this->trongLuong;
	wcout << L"\nNhập năng lượng vận chuyển: ";
	wcin >> this->NLVanChuyen;
	if (!this->validProp()) {
		wcout << L"\nThông tin không hợp lệ!";
		this->input();
	}
	else wcout << BIEN_END << L"Kết thúc" << BIEN_END;
}

inline float Carrier::NangLuongTieuThu(float S)
{
	return Robot::NangLuongTieuThu(S) + 4 * this->NLVanChuyen * S;
}

bool Carrier::validProp()
{
	return (this->NLVanChuyen >= 50 && this->NLVanChuyen <= 100);
}

void Carrier::setNL(float NL)
{
	this->NLVanChuyen = NL;
}
