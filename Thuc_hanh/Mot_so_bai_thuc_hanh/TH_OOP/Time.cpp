#include "Time.h"

Time::Time(int _hour, int _min, int _sec) {
	hour = _hour;
	min = _min;
	sec = _sec;
}
Time::~Time() {

}

void Time::input() {
	cout << "Nhap gio: ";
	do {
		cin >> hour;
		if (hour > 23 || hour < 0) cout << "Nhap chua dung.";
	} while (hour > 23 || hour < 0);
	cout << "Nhap phut: ";
	do {
		cin >> min;
		if (min > 60 || min < 0) {
			cout << "Nhap chua dung.";
		}
	} while (min > 60 || min < 0);
	cout << "Nhap giay: ";
	do {
		cin >> sec;
		if (sec > 60 || sec < 0) cout << "Nhap chua dung.";
	} while (sec > 60 || sec < 0);
}

bool Time::isValid() {
	return !(hour > 24 || hour < 0 || min > 60 || min < 0 || sec < 0 || sec > 60);
}

int Time::getSec() {
	return sec;
}

int Time::getMin() {
	return min;
}

int Time::getHour() {
	return hour;
}

void Time::setSec(int _sec) {
	sec = _sec;
}

void Time::setMin(int _min) {
	min = _min;
}

void Time::setHour(int _hour) {
	hour = _hour;
}

void Time::display(int type) {
	if (!isValid()) {
		cout << "Gio khong hop le!";
		return;
	}
	bool typeT = false;
	if (type == 12 && hour >= 12 && hour < 24) typeT = true;
	cout << hour % type << ":" << min << ":" << sec;
	if (type == 12) {
		if (typeT) cout << " PM";
		else cout << " AM";
	}
}

int Time::changeToSec() {
	return hour * 3600 + min * 60 + sec;
}

void Time::nextTime(int _hour, int _min, int _sec) {
	min += _min + (sec + _sec) / 60;
	hour += _hour + min / 60;
	hour %= 24;
	min %= 60;
	sec += _sec;
	sec %= 60;
}

void Time::nextTime(Time time) {
	min += time.min + (sec + time.sec) / 60;
	hour += time.hour + min / 60;
	hour %= 24;
	min %= 60;
	sec += time.sec;
	sec %= 60;
}

ostream& operator << (ostream& os, Time time) {
	if (!time.isValid()) {
		os << "Gio khong hop le!";
		return os;
	}
	os << time.hour % 24 << ":" << time.min << ":" << time.sec;
	return os;
}

Time Time::operator+(Time time) {
	Time target(this->hour, this->min, this->sec);
	target.nextTime(time);
	return target;
}

Time Time::operator-(Time time) {
	Time target(this->hour, this->min, this->sec);
	target.nextTime(time);
	return target;
}