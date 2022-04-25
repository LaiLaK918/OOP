#pragma once
#include "Robot.h"
#include "Pedion.h"
#include "Zattacker.h"
#include "Carrier.h"

class Babilon
{
	Robot** robots;
	int tong;
public:
	Babilon();
	~Babilon();
	void display(int S = 10);
	void inputRan();
	void input();
	Robot* maxTieuThu(int S = 10);
	float tongNangLuong(int S = 10);
};

