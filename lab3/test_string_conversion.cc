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
    std::istringstream is(c);
    Date d;
    is >> d;
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