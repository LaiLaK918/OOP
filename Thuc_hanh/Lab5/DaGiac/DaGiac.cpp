#include "DaGiac.h"

DaGiac::DaGiac()
{
	n = 1;
	point = NULL;
}

DaGiac::~DaGiac()
{
	delete point;
}

bool DaGiac::KiemTra()
{
	return true;
}
