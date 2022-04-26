#include "NhanVien.h"
#include "NVSanXuat.h"
#include "NVVanPhong.h"

int main() {
	int n;
	cout << "Nhap so cong nhan: ";
	cin >> n;
	NhanVien** nv = new NhanVien*[n];
	for (int i = 0; i < n; i++) {
		if (rand() % 2) nv[i] = new NVSanXuat();
		else nv[i] = new NVVanPhong();
	}
	for (int i = 0; i < n; i++) {
		nv[i]->input();
	}
	for (int i = 0; i < n; i++) {
		nv[i]->display();
	}
	return 0;
}