#pragma once
#include <iostream>
#include <string>
#include <fcntl.h>
#include <io.h>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
using namespace std;

#define BIEN "=========================="
#define BIEN_END "===================================="

class Robot
{
protected:
	int trongLuong;
public:
	Robot();
	~Robot();
	virtual void input() = 0;
	virtual void display(int S = 10);
	inline virtual float NangLuongTieuThu(float S);
	virtual bool validProp() = 0;
};