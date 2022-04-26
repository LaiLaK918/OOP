#include <math.h>

// base on Lagrange's four-square theorem
// https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem#Algorithms
// max result is 4

int sum_of_squares(int n) {
	int x = sqrt(n);
	// if n is square
	if (x * x == n) return 1;
	// if n = i*i+j*j
	for (int i = 0; i * i <= n; i++) {
		int j = sqrt(n - i * i);
		if (j * j + i * i == n) return 2;
	}
	// if format of n is n^k(8m+7) return 4
	while (n%4==0)
	{
		n /= 4;
	}
	if (n % 8 == 7) return 4;
	return 3;
}

