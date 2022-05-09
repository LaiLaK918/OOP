#include "CongTy.h"
using namespace TienLuong;

#include <iostream>
using namespace std;

int main() {
	CongTy* ct = new CongTy();
	ct->nhap();
	ct->xuat();
	cout << ct->tongLuong();
	cout << ct->timKiem(L"ABC");
	return 0;
}