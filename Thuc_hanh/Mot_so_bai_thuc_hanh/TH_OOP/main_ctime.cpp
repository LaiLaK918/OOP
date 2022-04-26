#include "CTimeSpan.h"

int main() {
	CTimeSpan c(Time(2,0,0), Time(0,59,59));
	cout << c;
	return 0;
}