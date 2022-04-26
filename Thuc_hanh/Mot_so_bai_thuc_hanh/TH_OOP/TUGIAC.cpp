#include "TUGIAC.h"

TUGIAC::TUGIAC()
{

}

TUGIAC::~TUGIAC()
{

}

void TUGIAC::display()
{
	for (int i = 0; i < 4; i++) {
		cout << "Diem: " << i + 1 << " ";
		point[i].display();
		cout << endl;
	}
}
