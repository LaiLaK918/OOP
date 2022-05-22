#include "SachLib.h"

int main() {
	int n;
	cin >> n;
	Sach** s1 = new Sach*[n];
	s1[0] = new SachGiaoKhoa();
	s1[1] = new TieuThuyet();
	s1[2] = new TapChi();
	for (int i = 0; i < 3; i++) {
		s1[i]->Nhap();
		s1[i]->Xuat();
	}
	return 0;
}