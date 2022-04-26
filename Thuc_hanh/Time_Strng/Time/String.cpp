#include "String.h"
#include <stack>

#define MAXCHAR 10000

unsigned int len_char_array(char c_arr[]) {
	char* tmp = c_arr;
	unsigned int count = 0;
	while (*tmp != '\0') {
		count++;
		tmp++;
	}
	return count;
}

unsigned int len_char_array(const char c_arr[]) {
	const char* tmp = c_arr;
	unsigned int count = 0;
	while (*tmp != '\0') {
		count++;
		tmp++;
	}
	return count;
}

String::String() {
	length = 0;
	str = NULL;
}

String::String(int _len) {
	length = _len;
	str = new char[_len+1];
	str[length] = '\0';
}

String::String(char _str[]) {
	length = len_char_array(_str);
	str = new char[length+1];
	for (int i = 0; i < length; i++) {
		str[i] = _str[i];
	}
	str[length] = '\0';
}

String::String(const char _str[]) {
	length = len_char_array(_str);
	str = new char[length+1];
	for (int i = 0; i < length; i++) {
		str[i] = _str[i];
	}
	str[length] = '\0';
}

String::String(const String& dup) {
	this->length = dup.length;
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++) {
		str[i] = dup.str[i];
	}
	str[length] = '\0';
}

String::~String() {
	if (str != NULL) delete str;
	str = NULL;
}

int String::strLen() {
	char* tmp = str;
	unsigned int count = 0;
	while (*tmp != '\0') {
		count++;
		tmp++;
	}
	return count;
}

char* String::getStr() {
	return str;
}

void String::add(String& other) {
	char* tmp;
	int this_len = this->strLen();
	int other_len = other.strLen();
	int tmp_len = this_len + other_len;
	tmp = new char[tmp_len+1];
	int i = 0;
	for (; i < this_len; i++) {
		tmp[i] = this->str[i];
	}
	for (int j = 0; j < other_len; j++, i++) {
		tmp[i] = other[j];
	}
	tmp[tmp_len] = '\0';
	this->str = tmp;
	length = tmp_len;
}

char& String::operator[] (int index) {
	return this->str[index];
}

ostream& operator << (ostream& os, String& s) {
	s.length = s.strLen();
	for (int i = 0; i < s.length; i++) {
		os << s[i];
	}
	return os;
}

istream& operator >> (istream& is, String& s) {
	char* ch = new char[MAXCHAR];
	for (int i = 0; i < MAXCHAR; i++) ch[i] = '\0';
	char tmp;
	int index = 0;
	while (is.get(tmp) && tmp != '\n') {
		ch[index++] = tmp;
	}
	s.length = len_char_array(ch);
	s.str = new char[s.length + 1];
	for (int i = 0; i < s.length; i++) {
		s[i] = ch[i];
	}
	s[s.length] = '\0';
	return is;
}

String& String::operator+(String& other) {
	char* tmp;
	int this_len = this->strLen();
	int other_len = other.strLen();
	int tmp_len = this_len + other_len;
	tmp = new char[tmp_len + 1];
	int i = 0;
	for (; i < this_len; i++) {
		tmp[i] = this->str[i];
	}
	for (int j = 0; j < other_len; j++, i++) {
		tmp[i] = other[j];
	}
	tmp[tmp_len] = '\0';
	String* result = new String();
	result->length = tmp_len;
	result->str = tmp;
	return *result;
}

void String::inverse() {
	stack<char> stc;
	for (int i = 0; i < length; i++) {
		stc.push(this->str[i]);
	}
	for (int i = 0; i < length; i++) {
		this->str[i] = stc.top();
		stc.pop();
	}
}