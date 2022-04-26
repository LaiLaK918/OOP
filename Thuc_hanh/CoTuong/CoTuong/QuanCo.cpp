#include "QuanCo.h"
using namespace ATCL2021;

QuanCo::QuanCo() {
	point = Point(0, 0);
	color = 0;
}

QuanCo::QuanCo(Point _point, bool _color) {
	point = _point;
	color = _color;
}

QuanCo::~QuanCo() {

}