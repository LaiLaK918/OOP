#include "Sort.h"

Sort::Sort() {
	n = 0;
	arr = NULL;
}

Sort::Sort(int nn) {
	n = nn;
	arr = new int[n];
}

Sort::~Sort() {

}


void Sort::print() {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
}

inline int Sort::getN() {
	return n;
}

inline void Sort::input(std::fstream& f) {
	for (int i = 0; i < n; i++) {
		f >> arr[i];
	}
}

inline bool Sort::ascending(const int& a, const int& b) {
	return a < b;
}

inline bool Sort::decending(const int& a, const int& b) {
	return a > b;
}

void Sort::inputRan()
{
	system("python3 ./gen.py");
	fstream f("a.txt", ios::in);
	f >> this->n;
	arr = new int[this->n];
	this->input(f);
	f.close();
}
