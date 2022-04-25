#pragma once
#include "Robot.h"
class Zattacker :
	public Robot
{
	float sucManh;
public:
	Zattacker(float sucManh = 20.f);
	~Zattacker();
	void input();
	void display(int S = 10);
	float NangLuongTieuThu(float S);
	bool validProp();
	void setSM(float SM);
};

