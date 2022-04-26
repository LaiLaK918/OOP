#include "CoTuong.h"
#include "ATCL2021.h"
using namespace ATCL2021;

CoTuong::CoTuong() {
	qc[0] = new Xe(Point(10, 1), 0);
	qc[1] = new Ma(Point(10, 2), 0);
	qc[2] = new Tuongg(Point(10, 3), 0);
	qc[3] = new Si(Point(10, 4), 0);
	qc[4] = new Tuong(Point(10, 5), 0);
	qc[5] = new Si(Point(10, 6), 0);
	qc[6] = new Tuongg(Point(10, 7), 0);
	qc[7] = new Ma(Point(10, 8), 0);
	qc[8] = new Xe(Point(10, 9), 0);
	qc[9] = new Phao(Point(8, 2), 0);
	qc[10] = new Phao(Point(8, 8), 0);
	for (int i = 11; i < 16; i++) {
		qc[i] = new Tot(Point(7, i - 10), 0);
	}
	qc[16] = new Xe(Point(1, 1), 1);
	qc[17] = new Ma(Point(1, 2), 1);
	qc[18] = new Tuongg(Point(1, 3), 1);
	qc[19] = new Si(Point(1, 4), 1);
	qc[20] = new Tuong(Point(1, 5), 1);
	qc[21] = new Si(Point(1, 6), 1);
	qc[22] = new Tuongg(Point(1, 7), 1);
	qc[23] = new Ma(Point(1, 8), 1);
	qc[24] = new Xe(Point(1, 9), 1);
	qc[25] = new Phao(Point(3, 2), 1);
	qc[26] = new Phao(Point(3, 8), 1);
	for (int i = 27; i < 32; i++) {
		qc[i] = new Tot(Point(4, i - 26), 1);
	}
}

CoTuong::~CoTuong() {
	delete[] qc;
}