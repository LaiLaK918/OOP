#pragma once
#include "integer.h"
#include "modarith.h"
#include "nbtheory.h"
#include <iostream>
using namespace std;
using namespace CryptoPP;

typedef Integer Int;



namespace ECC {
	namespace helperFunctionFFE {
		// compute EGCD gives g = au + bv
		Int EGCD(Int a, Int b, Int& u, Int& v);
		// find y such that xy=1 (mod n) when gives x and n
		Int InvMod(Int x, Int n);
	}

	class FFE {
		Int i_;
		Int P;
		void assign(Int i);
	public:
		FFE();
		explicit FFE(Int i, Int P);
		explicit FFE(Int P);
		FFE(const FFE& f);
		Int i() const;
		FFE operator - () const;
		FFE& operator = (Int i);
		FFE& operator = (const FFE& rhs);
		FFE& operator *= (const FFE& rhs);
		friend bool operator == (const FFE& lhs, const FFE& rhs);
		friend bool operator == (const FFE& lhs, Int rhs);
		friend bool operator != (const FFE& lhs, Int rhs);
		// must same P
		friend FFE operator / (const FFE& lhs, const FFE& rhs);
		friend FFE operator + (const FFE& lhs, Int rhs);
		friend FFE operator + (Int lhs, const FFE& rhs);
		friend FFE operator + (const FFE& lhs, const FFE& rhs);
		friend FFE operator - (const FFE& lhs, const FFE& rhs);
		friend FFE operator * (Int n, const FFE& rhs);
		friend FFE operator * (const FFE& lhs, const FFE& rhs);
		friend ostream& operator << (ostream& os, const FFE& rhs);
	};
}