#pragma once
#include <iostream>
#include "integer.h"
#include "FFE_Engine.h"
#include <vector>
using namespace CryptoPP;
using namespace std;
using namespace ECC;

namespace ECCCryptography {
	// y^2 = x^3 + ax + b (mod P)
	class EC {
	public:
		class ECP {
			friend class EC;
			FFE xCoordinate;
			FFE yCoordinate;
			EC* ec;
			ECP(Int x, Int y, Int P);
			void doublingMultiplierAlgorithm(Int multiplier, ECP& accumulatorContainer);
			ECP multiplyUsingScalar(Int inputScalar, const ECP& ecp);
		};
	};
}