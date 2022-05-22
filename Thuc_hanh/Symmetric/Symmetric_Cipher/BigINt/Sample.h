#pragma once
#include "integer.h"
#include <iostream>
using namespace std;
using namespace CryptoPP;

template <class P> class x {

};

template <> class x<Integer> {
	void fac() {
		Integer a;
		a = a % P;
	}
};
