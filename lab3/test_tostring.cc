#include <iostream>
#include <string>
#include <sstream>
#include "date.h"

template<typename T> std::string toString(const T& d) {
    std::ostringstream out;
    out << d;
    return out.str();
}

int main() {
    double d = 1.234;
    Date today;
    std::string sd = toString(d);
    std::string st = toString(today);
    std::cout << sd << std::endl;
    std::cout << st << std::endl;
}