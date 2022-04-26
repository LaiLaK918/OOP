#ifndef TIME_H
#define TIME_H

#pragma once
#include<iostream>
using namespace std;

class Time
{
	int sec;
	int min;
	int hour;
public:
	Time(int _hour = 0, int _min = 0, int _sec = 0);
	~Time();
	void input();
	int getSec();
	int getMin();
	int getHour();
	void setSec(int);
	void setMin(int);
	void setHour(int);
	void display(int type = 24);
	bool isValid();
	int changeToSec();
	void nextTime(int _hour = 0, int _min = 0, int _sec = 0);
	friend ostream& operator << (ostream&, Time);
	friend class CTimeSpan;
	Time operator + (Time);
	Time operator - (Time);
	void nextTime(Time);
};

#endif