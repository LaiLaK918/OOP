#include "ECC_cryptography.h"
using namespace ECCCryptography;

void ECCCryptography::EC::ECP::doublingMultiplierAlgorithm(Int multiplier, ECP& accumulatorContainer)
{
	if (multiplier > 0) {
		ECP doublingVal = accumulatorContainer;
		for (int c = 0; c < multiplier; c++) {
			doublingVal += doublingVal;
		}
		accumulatorContainer = doublingVal;
	}
}

EC::ECP ECCCryptography::EC::ECP::multiplyUsingScalar(Int inputScalar, const ECP& ecp)
{
	ECP acContainer = ecp;
	
	return ECP();
}
