#include <iostream>
#include <fstream>
using namespace std;

#define FILEPATH "G:\\Code\\Text\\Sort Test.txt"

void interchangeSort(int* arr, const int &n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[i]) swap(arr[i], arr[j]);
		}
	}
}

void print(int* arr, const int &n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	fstream f(FILEPATH, ios::in);
	int n;
	f >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		f >> arr[i];
	}
	print(arr, n);
	cout << endl;
	interchangeSort(arr, n);
	print(arr, n);
	f.close();
}