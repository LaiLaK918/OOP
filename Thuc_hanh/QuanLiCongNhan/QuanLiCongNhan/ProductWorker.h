#pragma once
#include "Worker.h"

#ifndef PRODUCTWORKER

#define PRODUCTWORKER

class ProductWorker : public Worker{
    int numProduct;
public:
    ProductWorker(){}
    ProductWorker(string _name,Day* _birth, string _place, string _type,int _numProduct):Worker(_name,_birth,_place,_type),numProduct(_numProduct){}
    virtual ~ProductWorker(){}
    void display(){
        cout << "Name: " << name;
        cout << "\nDay of birth: " << birth;
        cout << "\nPlace: " << place;
        cout << "\nType: " << type;
        cout << "\nNumber of product: " << numProduct;
        cout << "\nSalary" << salary();
    }
    double salary(){
        return this->numProduct*20000;
    }
    void setInfo(string _name,Day* _birth, string _place, string _type,int _numProduct){
        name = _name;
        birth = _birth;
        place = _place;
        type = _type;
        numProduct = _numProduct;
    }
    void setNumProduct(int _numProduct){
        numProduct = _numProduct;
    }
    int getNumProduct(){
        return this->numProduct;
    }
};

#endif