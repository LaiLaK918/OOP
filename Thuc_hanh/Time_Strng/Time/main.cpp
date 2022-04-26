#include "Time.h"
#include "Stack.h"
#include <string>

string alphabet;

void gen_alpha() {
	for (int i = 0; i < 10; i++) {
		alphabet += to_string(i);
	}
	char lower = 'a';
	while (lower <= 'z') {
		alphabet += lower;
		lower++;
	}
	char upper = 'A';
	while (upper <= 'Z') {
		alphabet += upper;
		upper++;
	}
	alphabet += "+\\";
}

void ToBase(int number, int base = 10) {
	string res = "";
	while (number > 0) {
		res = ::alphabet[(number % base)%(::alphabet.length())] + res;
		number /= base;
	}
	cout << res;
}

int main() {
	//Time time(24, 0, 0);
	//time.display(12);
	gen_alpha();
	cout << ::alphabet << endl << ::alphabet.length() << endl;
	ToBase(65537, 16);
	return 0;
}