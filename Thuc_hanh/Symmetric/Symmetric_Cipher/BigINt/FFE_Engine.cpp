#include "FFE_Engine.h"

using ECC::FFE;

Int ECC::helperFunctionFFE::EGCD(Int a, Int b, Int& u, Int& v)
{
	u = 0;
	v = 1;
	Int g = a;
	Int u1 = 0;
	Int v1 = 1;
	Int g1 = b;
	while (g1 != 0) {
		Int q = g / g1;
		Int t1 = u - q * u1;
		Int t2 = v - q * v1;
		Int t3 = g - q * g1;
		u = u1;
		v = v1;
		g = g1;
		u1 = t1;
		v1 = t2;
		g1 = t3;
	}
	return g;
}

Int ECC::helperFunctionFFE::InvMod(Int x, Int n)
{
	x %= n;
	Int u, v, g, z;
	g = EGCD(x, n, u, v);
	if (g != 1) {
		z = 0;
	}
	else z = u % n;
	return z;
}

void ECC::FFE::assign(Int i)
{
	i_ = i;
	if (i < 0) {
		i_ = (i % P) + 2 * P;
	}
	i_ %= P;
}

ECC::FFE::FFE()
{
	i_ = 0;
	P = 0;
}

ECC::FFE::FFE(Int i, Int P)
{
	this->i_ = i;
	this->P = P;
}

ECC::FFE::FFE(Int P)
{
	i_ = 0;
	this->P = P;
}

ECC::FFE::FFE(const FFE& f)
{
	this->i_ = f.i_;
	this->P = f.P;
}

Int ECC::FFE::i() const
{
	return this->i_;
}

ECC::FFE ECC::FFE::operator-() const
{
	return FFE(-i_, P);
}

ECC::FFE& ECC::FFE::operator=(Int i)
{
	assign(i);
	return *this;
}

ECC::FFE& ECC::FFE::operator=(const FFE& rhs)
{
	i_ = rhs.i_;
	P = rhs.P;
	return *this;
}

FFE& ECC::FFE::operator*=(const FFE& rhs)
{
	i_ = (i_ * rhs.i_) % P;
	return *this;
}

bool ECC::operator==(const FFE& lhs, const FFE& rhs)
{
	return ((lhs.i_ == rhs.i_) && (lhs.P == rhs.P));
}

bool ECC::operator==(const FFE& lhs, Int rhs)
{
	return (lhs.i_ == rhs);
}

bool ECC::operator!=(const FFE& lhs, Int rhs)
{
	return  (lhs.i_ == rhs);
}

FFE ECC::operator/(const FFE& lhs, const FFE& rhs)
{
	return FFE(lhs.i_ * helperFunctionFFE::InvMod(rhs.i_, rhs.P), lhs.P);
}

FFE ECC::operator+(const FFE& lhs, Int rhs)
{
	return FFE(lhs.i_ + rhs, lhs.P);
}

FFE ECC::operator+(Int lhs, const FFE& rhs)
{
	return FFE(lhs + rhs.i_, rhs.P);
}

FFE ECC::operator+(const FFE& lhs, const FFE& rhs)
{
	return FFE(lhs.i_ + rhs.i_, lhs.P);
}

FFE ECC::operator-(const FFE& lhs, const FFE& rhs)
{
	return FFE(lhs.i_ - rhs.i_, lhs.P);
}

FFE ECC::operator*(Int n, const FFE& rhs)
{
	return FFE(n * rhs.i_, rhs.P);
}

FFE ECC::operator*(const FFE& lhs, const FFE& rhs)
{
	return FFE(lhs.i_ * rhs.i_, lhs.P);
}

ostream& ECC::operator<<(ostream& os, const FFE& rhs)
{
	os << rhs.i_;
	return os;
}
