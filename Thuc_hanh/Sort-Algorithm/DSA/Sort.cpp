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

inline void Sort::_swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

inline void Sort::nhapMang(std::fstream& f) {
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