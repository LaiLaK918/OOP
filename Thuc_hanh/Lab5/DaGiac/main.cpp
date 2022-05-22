#include "DaGiacLib.h"

int main() {
	//DaGiac* a = new TamGiac();
	//a->Nhap();
	//a->Xuat();
	//a->TinhTien(1, 1);
	//cout << endl;
	//a->Xuat();
	//DaGiac* b = new TuGiac();
	//b->Nhap();
	//b->Xuat();
	//b->TinhTien(2,2);
	//cout << endl;
	//b->Xuat();
	Point2D x(1, 1);
	TuGiac* c = new HinhBinhHanh();
	c->Nhap();
	cout << c->KiemTra() << endl;
	c->TinhTien(x);
	c->Xuat();
	cout << endl;
	TuGiac* d = new HinhChuNhat();
	d->Nhap();
	cout << d->KiemTra() << endl;
	d->TinhTien(x);
	d->Xuat();
	cout << endl;
	TuGiac* e = new HinhVuong();
	e->Nhap();
	cout << e->KiemTra() << endl;
	e->TinhTien(x);
	e->Xuat();
	cout << endl;
	return 0;
}