#pragma once
#include "Worker.h"

#ifndef DAILYWORKER

#define DAILYWORKER

class DailyWorker : public Worker{
private:
    int workDay;
public:
    DailyWorker(){}
    DailyWorker(string _name, Day* _birth, string _place, string _type, int _workDay) : 
    Worker(_name, _birth, _place, _type), workDay(_workDay) {}
    ~DailyWorker(){}
    void display(){
        cout << "Name: " << name;
        cout << "\nDay of birth: " << birth;
        cout << "\nPlace: " << place;
        cout << "\nType: " << type;
        cout << "\nWorkday: " << workDay;
        cout << "\nSalary" << salary();
    }
    double salary(){
        return workDay*200000;
    }
    void setWorkDay(int _workDay){
        workDay = _workDay;
    }
    int getWorkDay(){
        return workDay;
    }
    void setInfo(string _name, Day* _birth, string _place, string _type, int _workDay){
        name = _name;
		birth = _birth;
		place = _place;
		type = _type;
        workDay = _workDay;
    }
};

#endif