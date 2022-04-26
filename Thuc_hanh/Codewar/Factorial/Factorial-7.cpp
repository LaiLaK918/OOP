#include <algorithm>
#include <iterator>
#include <string>
#include <iostream>
using namespace std;
//big endian
int digit(char c) {
    return c - '0';
}
char to_char(int n) {
    return '0' + n;
}
class Number {
    string number;
public:
    Number() = default;
    Number(string str) :number(str) {}
    Number(int n) {
        if (n == 0) {
            number = "";
        }
        while (n > 0) {
            number.push_back(to_char(n % 10));
            n = n / 10;
        }
    }
    friend Number operator+(const Number& n1, const Number& n2) {
        int max_size = max(n1.number.size(), n2.number.size());
        string num1 = n1.number + string(max_size - n1.number.size(), '0');
        string num2 = n2.number + string(max_size - n2.number.size(), '0');
        string result = "";
        int accumulate = 0;
        for (int i = 0; i < max_size; i++) {
            int inter = digit(num1[i]) + digit(num2[i]) + accumulate;
            accumulate = inter / 10;
            result.push_back(to_char(inter % 10));
        }
        if (accumulate != 0) {
            result.push_back(to_char(accumulate));
        }
        return Number(result);
    }
    friend bool operator==(const Number& n1, const Number& n2) {
        return n1.number == n2.number;
    }
    friend bool operator!=(const Number& n1, const Number& n2) {
        return !(n1.number == n2.number);
    }
    friend Number operator*(const Number& n1, const Number& n2) {
        int max_size = max(n1.number.size(), n2.number.size());
        string num1 = n1.number;
        string num2 = n2.number;
        Number result;
        for (int i = 0; i < num1.size(); i++) {
            int accumulate = 0;
            string inbetween = "";
            for (int j = 0; j < num2.size(); j++) {
                int inter = digit(num2[j]) * digit(num1[i]) + accumulate;
                accumulate = inter / 10;
                inbetween.push_back(to_char(inter % 10));
            }
            if (accumulate != 0) {
                inbetween.push_back(to_char(accumulate));
            }
            result = result + Number(string(i, '0') + inbetween);
        }
        return result;
    }
    string str() {
        return string(number.rbegin(), number.rend());
    }
    friend ostream& operator<<(ostream& os, const Number& n1) {
        os << string(n1.number.rbegin(), n1.number.rend());
        return os;
    }
};
string factorial(int factorial) {
    Number n("1");
    for (int i = 1; i < factorial + 1; i++) {
        n = Number(i) * n;
    }
    return n.str();
}
