#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "date.h"

using std::cout;
using std::endl;
using std::istream;

template<typename T> T string_cast(const char c[]);

template<> int string_cast<int>(const char c[]) {
    return std::atoi(c);
}

template<> double string_cast<double>(const char c[]) {
    return std::atof(c);
}

template<> Date string_cast<Date>(const char c[]) {
    std::string s;
    int year;
    for (int i = 0; i < 4; i++) {
        s += c[i];
    }
    year = stoi(s);
    s = "";
    int month;
    for (int i = 5; i < 7; i++) {
        s += c[i];
    }
    month = stoi(s);
    s = "";
    int day;
    for (int i = 8; i < 10; i++) {
        s += c[i];
    }
    day = stoi(s);
    Date d(year, month, day);
    return d;
}

int main() {
    try {
        int i = string_cast<int>("123");
        double d = string_cast<double>("12.34");
        Date date = string_cast<Date>("2015-01-10");
        cout << date << endl;
    } catch (std::invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
}