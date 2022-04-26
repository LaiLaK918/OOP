#ifndef STRING_H
#define STRING_H

#pragma once
#include<iostream>
using namespace std; 

class String
{
	int length;
	char* str;
public:
	String();
	String(int);
	String(char[]);
	String(const char[]);
	String(const String&);
	~String();
	int strLen();
	void add(String&);
	char* getStr();
	void inverse();
	friend istream& operator >> (istream&, String&);
	friend ostream& operator << (ostream&, String&);
	char& operator [] (int);
	String& operator + (String&);
};

#endif // !STRING_H