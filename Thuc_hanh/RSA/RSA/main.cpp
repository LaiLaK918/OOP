#include "integer.h"
#include "rsa.h"
#include "modarith.h"
#include "nbtheory.h"
#include "osrng.h"

using namespace CryptoPP;

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//#define FILEPATH "C:\\Users\\hoang\\source\\repos\\RSA\\RSA\\privateKey.txt"
//#define FILEPATHENC "C:\\Users\\hoang\\source\\repos\\RSA\\RSA\\encrypted.txt"

Integer privateKey[2];

Integer gcdExtended(Integer a, Integer b, Integer* x, Integer* y);

// Function to find modulo inverse of a
Integer modInverse(Integer a, Integer m)
{
	Integer x, y;
	Integer g = gcdExtended(a, m, &x, &y);
	if (g != 1)
		return -1;
	else
	{
		// m is added to handle negative x
		Integer res = (x % m + m) % m;
		return res;
	}
}

// Function for extended Euclidean Algorithm
Integer gcdExtended(Integer a, Integer b, Integer* x, Integer* y)
{

	// Base Case
	if (a == 0)
	{
		*x = 0, * y = 1;
		return b;
	}

	// To store results of recursive call
	Integer x1, y1;
	Integer gcd = gcdExtended(b % a, a, &x1, &y1);

	// Update x and y using results of recursive
	// call
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

Integer encryptRSA() {
	string message;
	cout << "Enter your message: ";
	cin >> message;
	Integer m((const byte*)message.data(), message.size());
	AutoSeededRandomPool rng;
	InvertibleRSAFunction params;
	params.GenerateRandomWithKeySize(rng, 1024);
	const Integer& p = params.GetPrime1();
	const Integer& q = params.GetPrime2();
	Integer n = p * q;
	Integer e("0x10001");
	Integer c = a_exp_b_mod_c(m, e, n);
	Integer d = modInverse(e, (p - 1) * (q - 1));
	privateKey[0] = d;
	privateKey[1] = n;
	cout << "Modulus: " << hex << n;
	cout << "\nExponent: " << hex << e;
	fstream f("output.txt", ios::out);
	f << "n = " << n << "\n";
	f << "e = " << e << "\n";
	f << "c = " << c;
	f.close();
	//fstream f2(FILEPATH, ios::out);
	//f2 << "n = " << n << "\n";
	//f2 << "d = " << d;
	//f2.close();
	return c;
}

Integer decryptRSA(Integer ciphertext) {
	const Integer& c = ciphertext;
	const Integer& d = privateKey[0];
	const Integer& n = privateKey[1];
	Integer m = a_exp_b_mod_c(c, d, n);
	return m;
}

int main() {
	//string message = "aduwat who are you?";
	//CryptoPP::Integer m((const byte*)message.data(), message.size());
	//cout << m;
	//InvertibleRSAFunction params;
	//AutoSeededRandomPool rng;
	//params.GenerateRandomWithKeySize(rng, 3072);
	//cout << params.GetPrime1() << endl << params.GetPrime2() << endl << params.GetModulus();
	Integer c = encryptRSA();
	cout << "\nCiphertext: " << hex << c << endl;
	Integer m = decryptRSA(c);
	string message;
	size_t req = m.MinEncodedSize();
	message.resize(req);
	m.Encode((byte*)message.data(), message.size());
	//cout << "\nMessage: " << message;
	system("pause");
	return 0;
}