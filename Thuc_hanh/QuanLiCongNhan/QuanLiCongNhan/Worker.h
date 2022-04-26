#pragma once
#include "Day.h"
#include <iostream>
using namespace std;

class Worker
{
protected:
	string name;
	Day* birth;
	string place;
	string type;
public:
	Worker() {}
	Worker(string _name, Day* _birth, string _place, string _type) {
		name = _name;
		birth = _birth;
		place = _place;
		type = _type;
	}
	~Worker() {}
	virtual void display() = 0;
	void setInfo(string _name, Day* _birth, string _place, string _type) {
		name = _name;
		birth = _birth;
		place = _place;
		type = _type;

	}
	virtual double salary() = 0;
};