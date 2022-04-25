#include "Robot.h"

Robot::Robot()
{
	this->trongLuong = 0;
}

Robot::~Robot()
{

}

void Robot::display(int S)
{
	wcout << L"\nTrọng lượng: " << this->trongLuong;
}

inline float Robot::NangLuongTieuThu(float S)
{
	return this->trongLuong * S;
}
