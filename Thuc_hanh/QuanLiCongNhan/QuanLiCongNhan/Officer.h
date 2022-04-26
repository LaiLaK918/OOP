#include "Worker.h"

#ifndef OFFICER

#define OFFICER

class Officer: public  Worker {
    double salaryFactor;
    double baseSalary;
public:
    Officer(){}
    Officer(string _name,Day* _birth, string _place, string _type,double _salaryFactor,double _baseSalary):Worker(_name,_birth,_place,_type),salaryFactor(_salaryFactor),baseSalary(_baseSalary){}
    virtual ~Officer(){}
    void display(){
        cout << "Name: " << name;
        cout << "\nDay of birth: " << birth;
        cout << "\nPlace: " << place;
        cout << "\nType: " << type;
        cout << "\nSalary" << salary();
    }
    double salary(){
        return salaryFactor*baseSalary;
    }
    void setInfo(string _name,Day* _birth, string _place, string _type,double _salaryFactor,double _baseSalary){
        name = _name;
        birth = _birth;
        place = _place;
        type = _type;
        salaryFactor = _salaryFactor;
        baseSalary = _baseSalary;
    }
    void setSalaryFactor(double _salaryFactor){
        salaryFactor = _salaryFactor;
    }
    void setBaseSalary(double _baseSalary){
        baseSalary = _baseSalary;
    }
    double getSalaryFactor(){
        return salaryFactor;
    }
    double getBaseSalary(){
        return baseSalary;
    }
};

#endif