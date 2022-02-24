#include <ctime>  // time and localtime
#include "date.h"
#include <iostream>
#include <ios>
#include <string>

using std::ostream;
using std::istream;
using std::ios_base;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	if (month != 12) {
		if (daysPerMonth[month - 1] == day) {
			day = 1;
			month++;
		}
		else {
			day++;
		}
	}
	else {
		year++;
		month = 1;
		day = 1;
	}
}

ostream& operator<<(ostream &os, const Date& d) {
	os << d.getYear() << "-" << d.getMonth() << "-" << d.getDay();
	return os;
}

istream& operator>>(istream &is, Date& d) {
	if (is) {
		char* buffer = new char[4];
		is.read(buffer, 4);
		for (int i = 0; i < 4; i++) {
			if (!isdigit(buffer[i])) {
				is.setstate(ios_base::failbit);
				return is;
			}
		}
		d.year = atoi(buffer);
		buffer = new char[1];
		is.read(buffer, 1);
		if (buffer[0] != '-') {
			is.setstate(ios_base::failbit);
			return is;
		}
		buffer = new char[2];
		is.read(buffer, 2);
		for (int i = 0; i < 2; i++) {
			if (!isdigit(buffer[i])) {
				is.setstate(ios_base::failbit);
				return is;
			}
		}
		if (atoi(buffer) > 12) {
			is.setstate(ios_base::failbit);
			return is;
		}
		d.month = atoi(buffer);
		buffer = new char[1];
		is.read(buffer, 1);
		if (buffer[0] != '-') {
			is.setstate(ios_base::failbit);
			return is;
		}
		buffer = new char[2];
		is.read(buffer, 2);
		for (int i = 0; i < 2; i++) {
			if (!isdigit(buffer[i])) {
				is.setstate(ios_base::failbit);
				return is;
			}
		}
		if (atoi(buffer) > 31) {
			is.setstate(ios_base::failbit);
			return is;
		}
		d.day = atoi(buffer);
	}
	return is;
}