#include "CTimeSpan.h"

CTimeSpan::CTimeSpan(int _span){
	span = _span;
}

CTimeSpan::~CTimeSpan() {

}

ostream& operator << (ostream& os, CTimeSpan timeS) {
	os << timeS.span;
	return os;
}

CTimeSpan CTimeSpan::operator+(CTimeSpan other) {
	CTimeSpan target(this->span + other.span);
	return target;
}

CTimeSpan CTimeSpan::operator-(CTimeSpan other) {
	CTimeSpan target(this->span - other.span);
	return target;
}

bool CTimeSpan::operator<(CTimeSpan other) {
	return this->span < other.span;
}

bool CTimeSpan::operator<=(CTimeSpan other) {
	return this->span <= other.span;
}

bool CTimeSpan::operator>(CTimeSpan other) {
	return this->span > other.span;
}

bool CTimeSpan::operator>=(CTimeSpan other) {
	return this->span >= other.span;
}

bool CTimeSpan::operator==(CTimeSpan other) {
	return this->span == other.span;
}

bool CTimeSpan::operator != (CTimeSpan other) {
	return this->span != other.span;
}