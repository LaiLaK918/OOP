#pragma once
#include <iostream>

#ifndef DAY

#define DAY

class Day{
private:
    int day;
    int month;
    int year;
public:
    Day(){}
    Day(int _day, int _month, int _year) {
        day = _day;
        month = _month;
        year = _year;
    }
    ~Day(){}
    bool isValid(){
        return (day>0) && (day<32) && (month>0) && (month<13);
    }
    friend std::istream& operator >> (std::istream& is, Day& day){
        std::cout << "Nhap ngay thang nam (xx xx xxxx)";
        is >> day.day >> day.month >> day.year;
        return is;
    }
    friend std::ostream& operator << (std::ostream& os, Day &day){
        if (day.isValid())
        os << day.day << "/" << day.month << "/" << day.year;
        else os << "Invalid";
        return os;
    }
};

#endif