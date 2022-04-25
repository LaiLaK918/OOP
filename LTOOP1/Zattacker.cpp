#include "Zattacker.h"

Zattacker::Zattacker(float sucManh)
{
	this->trongLuong = 50;
	this->sucManh = sucManh;
}

Zattacker::~Zattacker()
{

}

void Zattacker::input()
{
	wcout << endl << BIEN << L"Nhập thông tin robot loại Zattacker" << BIEN;
	wcout << L"\nĐã biết thông tin - Trọng lượng: " << this->trongLuong;
	wcout << L"\nNhập sức mạnh: ";
	wcin >> this->sucManh;
	if (!this->validProp()) {
		wcout << L"\nThông tin không hợp lệ!";
		this->input();
	}
	else wcout << BIEN_END << L"Kết thúc" << BIEN_END;
}

void Zattacker::display(int S)
{
	wcout << endl << BIEN << L"Robot loại Zattacker" << BIEN;
	Robot::display();
	wcout << L"\nSức mạnh: " << this->sucManh;
	wcout << L"\nChức năng: tấn công.";
	wcout << L"\nNăng lượng tiêu thụ: " << this->NangLuongTieuThu(S);
}

float Zattacker::NangLuongTieuThu(float S)
{
	return Robot::NangLuongTieuThu(S) + this->sucManh * this->sucManh * S;
}

bool Zattacker::validProp()
{
	return (this->sucManh >= 20 && this->sucManh <= 30);
}

void Zattacker::setSM(float SM)
{
	this->sucManh = SM;
}
