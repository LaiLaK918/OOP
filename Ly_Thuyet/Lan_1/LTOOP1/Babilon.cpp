#include "Babilon.h"

Babilon::Babilon()
{
	robots = NULL;
	tong = 0;
}

Babilon::~Babilon()
{
	delete[] robots;
}

void Babilon::display(int S)
{
	for (int i = 0; i < tong; i++) {
		robots[i]->display(S);
	}
}

void Babilon::inputRan()
{
	wcout << L"\nSố lượng robot loại Pedion, Zattacker, Carrier: ";
	int A, B, C;
	wcin >> A >> B >> C;
	robots = new Robot * [A + B + C];
	tong = A + B + C;

	for (int i = 0; i < A; i++) {
		srand(time(0) + i * 100);
		float x = 1 + static_cast<float> (rand()) / static_cast<float> (RAND_MAX / (5 - 1));
		robots[i] = new Pedion(x);
	}

	for (int i = 0; i < B; i++) {
		srand(time(0) + i * 100);
		float x = 20 + static_cast<float> (rand()) / static_cast<float> (RAND_MAX / (30 - 20));
		robots[A + i] = new Zattacker(x);
	}

	for (int i = 0; i < C; i++) {
		srand(time(0) + i * 100);
		float x = 50 + static_cast<float> (rand()) / static_cast<float> (RAND_MAX / (100 - 50));
		robots[A + B + i] = new Carrier(x);
	}
}

void Babilon::input()
{
	wcout << L"Tổng số robot: ";
	wcin >> this->tong;
	this->robots = new Robot * [tong];
	for (int i = 0; i < tong; i++) {
		tryAgain:
		wcout << L"\nLoại robot: ";
		wstring s;
		wcin >> s;
		if (s == L"Carrier") {
			robots[i] = new Carrier();
			robots[i]->input();
		}
		else if (s == L"Pedion") {
			robots[i] = new Pedion();
			robots[i]->input();
		}
		else if (s == L"Zattacker") {
			robots[i] = new Zattacker();
			robots[i]->input();
		}
		else {
			wcout << L"Loại không hợp lệ, nhập lại.";
			goto tryAgain;
		}
	}
}

Robot* Babilon::maxTieuThu(int S)
{
	if (!tong) {
		wcout << L"\nKhông có robot nào.";
		return NULL;
	}
	else {
		Robot* max = robots[0];
		for (int i = 1; i < tong; i++) {
			if (robots[i]->NangLuongTieuThu(S) > max->NangLuongTieuThu(S)) {
				max = robots[i];
			}
		}
		return max;
	}
}

float Babilon::tongNangLuong(int S)
{
	float tong = 0.f;
	for (int i = 0; i < this->tong; i++) {
		tong += robots[i]->NangLuongTieuThu(S);
	}
	return tong;
}
