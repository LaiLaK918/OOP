#include "SoPhuc.h"
#include <math.h>

SoPhuc::SoPhuc(float _thuc, float _ao) {
	thuc = _thuc;
	ao = _ao;
}

SoPhuc::~SoPhuc() {

}

void SoPhuc::nhap() {
	cin >> thuc >> ao;
}

void SoPhuc::xuat() {
	if (ao == 0 && thuc == 0) cout << 0;
	else {
		if (ao == 0) cout << thuc;
		else if (thuc == 0) cout << ao << "i";
		else {
			cout << thuc;
			if (ao > 0) cout << "+" << ao;
			else cout << ao;
			cout << "i";
		}
	}
}

float SoPhuc::abs(bool mu2) {
	if (mu2) return thuc * thuc + ao * ao;
	return sqrt(thuc * thuc + ao * ao);
}

void SoPhuc::setThuc(float _thuc) {
	thuc = _thuc;
}

void SoPhuc::setAo(float _ao) {
	ao = _ao;
}

float SoPhuc::getThuc()  {
	return thuc;
}

float SoPhuc::getAo()  {
	return ao;
}

SoPhuc SoPhuc::cong(SoPhuc sp)  {
	SoPhuc other = SoPhuc(this->thuc + sp.thuc, this->ao + sp.ao);
	return other;
}

SoPhuc SoPhuc::tru(SoPhuc sp)  {
	return *(new SoPhuc(this->thuc - sp.thuc, this->ao - sp.ao));
}

SoPhuc SoPhuc::nhan(SoPhuc sp)  {
	return *(new SoPhuc(this->thuc * sp.thuc - this->ao * sp.ao, this->thuc * sp.ao + this->ao * sp.thuc));
}

SoPhuc SoPhuc::chia(SoPhuc sp)  {
	return *(new SoPhuc((this->thuc * sp.thuc + this->ao * sp.ao) / sp.abs(true), (this->ao * sp.thuc - this->thuc * sp.ao) / sp.abs(true)));
}

ostream& operator << (ostream& os, SoPhuc sp) {
	if (sp.ao == 0 && sp.thuc == 0) os << 0;
	else {
		if (sp.ao == 0) os << sp.thuc;
		else if (sp.thuc == 0) os << sp.ao << "i";
		else {
			os << sp.thuc;
			if (sp.ao > 0) os << "+" << sp.ao;
			else os << sp.ao;
			os << "i";
		}
	}
	return os;
}

istream& operator >> (istream& is, SoPhuc& sp) {
	cout << "Nhap thuc ao(thuc ao-> 2 3 == 2+3i): ";
	is >> sp.ao >> sp.thuc;
	return is;
}

SoPhuc SoPhuc::operator + ( SoPhuc sp)  {
	return this->cong(sp);
}

SoPhuc SoPhuc::operator - ( SoPhuc sp)  {
	//SoPhuc res(this->thuc - sp.thuc, this->ao - sp.ao);
	//return res;
	return this->tru(sp);
}

SoPhuc SoPhuc::operator * ( SoPhuc sp)  {
	SoPhuc res = SoPhuc(this->thuc * sp.thuc - this->ao * sp.ao, this->thuc * sp.ao + this->ao * sp.thuc);
	return res;
}

SoPhuc SoPhuc::operator / ( SoPhuc sp)  {
	SoPhuc res = SoPhuc((this->thuc * sp.thuc + this->ao * sp.ao) / sp.abs(true), (this->ao * sp.thuc - this->thuc * sp.ao) / sp.abs(true));
	return res;
}
bool SoPhuc::operator == ( SoPhuc sp)  {
	return (this->thuc == sp.thuc && this->ao == sp.ao);
}

bool SoPhuc::operator != ( SoPhuc sp)  {
	return (this->thuc != sp.thuc || this->ao != sp.ao);
}

bool SoPhuc::operator > ( SoPhuc sp)  {
	return this->abs() > sp.abs();
}
bool SoPhuc::operator >= ( SoPhuc sp)  {
	return this->abs() >= sp.abs();
}
bool SoPhuc::operator < ( SoPhuc sp)  {
	return this->abs() < sp.abs();
}
bool SoPhuc::operator <= ( SoPhuc sp)  {
	return this->abs() <= sp.abs();
}
