#include "PhanSo.h"
PhanSo::PhanSo(int _tu, int _mau) {
	tu = _tu;
	mau = _mau;
}

PhanSo::~PhanSo() {

}

int PhanSo::_gcd(int _tu, int _mau) {
	return _mau == 0 ? _tu : _gcd(_mau, _tu % _mau);
}

void PhanSo::rut_gon() {
	int uc = _gcd(tu, mau);
	tu /= uc;
	mau /= uc;
}

PhanSo PhanSo::operator+(PhanSo ps) {
	PhanSo target(this->tu * ps.mau + this->mau * ps.tu, this->mau * ps.mau);
	target.rut_gon();
	return target;
}

PhanSo PhanSo::operator-(PhanSo ps) {
	PhanSo target(this->tu * ps.mau - this->mau * ps.tu, this->mau * ps.mau);
	target.rut_gon();
	return target;
}

PhanSo PhanSo::operator*(PhanSo ps) {
	PhanSo target(this->tu * ps.tu, this->mau * ps.mau);
	target.rut_gon();
	return target;
}

PhanSo PhanSo::operator/(PhanSo ps) {
	PhanSo target(this->tu * ps.mau, this->mau * ps.tu);
	target.rut_gon();
	return target;
}

bool PhanSo::operator==(PhanSo ps) {
	this->rut_gon();
	ps.rut_gon();
	return (this->tu == ps.tu && this->mau == ps.mau);
}

bool PhanSo::operator!=(PhanSo ps) {
	this->rut_gon();
	ps.rut_gon();
	return (this->tu != ps.tu || this->mau != ps.mau);
}

bool PhanSo::operator<(PhanSo ps) {
	return (this->tu * 1. / this->mau < ps.tu * 1. / ps.mau);
}

bool PhanSo::operator<=(PhanSo ps) {
	return (this->tu * 1. / this->mau <= ps.tu * 1. / ps.mau);
}

bool PhanSo::operator>(PhanSo ps) {
	return (this->tu * 1. / this->mau > ps.tu * 1. / ps.mau);
}

bool PhanSo::operator>=(PhanSo ps) {
	return (this->tu * 1. / this->mau >= ps.tu * 1. / ps.mau);
}

ostream& operator << (ostream& os, PhanSo ps) {
	ps.rut_gon();
	if (ps.tu == ps.mau || ps.tu == 0) os << ps.tu;
	else os << ps.tu << "/" << ps.mau;
	return os;
}

istream& operator >> (istream& is, PhanSo& ps) {
	cout << "Nhap tu: ";
	is >> ps.tu;
	cout << "Nhap mau: ";
	is >> ps.mau;
	return is;
}