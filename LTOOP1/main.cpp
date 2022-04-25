#include <iostream>
#include <string>
#include <fcntl.h>
#include <io.h>
using namespace std;

#include "Zattacker.h"
#include "Carrier.h"
#include "Pedion.h"
#include "Babilon.h"

int main() {
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	Babilon* babilons = new Babilon;
	babilons->inputRan();
	babilons->display(10); // bỏ 10 vẫn được
	Robot* max = babilons->maxTieuThu(10);
	wcout << L"\nRobot tiêu thụ năng lượng nhiều nhất trong đoàn: ";
	max->display(10); // bỏ 10 vẫn được
	wcout << L"\nTổng năng lượng tiêu thụ của đoàn robot: " << babilons->tongNangLuong();
	return 0;
}