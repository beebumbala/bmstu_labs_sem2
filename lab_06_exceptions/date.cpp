#include "date.h"
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>


// DateException
DateException::DateException(int day, int month, int year, const std::string& error_field, const std::string& error_msg)
    : out_of_range(error_msg), _day(day), _month(month), _year(year), _errorField(error_field) {}

void DateException::print() const {
    std::cout << "date exception in object: {d: " << getDay() << ", m: " << getMonth() << ", y: " << getYear() << "}" << std::endl;
    std::cout << _errorField << " is invalid" << std::endl;
    std::cout << what() << std::endl;
}

int DateException::getDay() const { return _day; }
int DateException::getMonth() const { return _month; }
int DateException::getYear() const { return _year; }
std::string DateException::getErrorField() const { return _errorField; }


// Date
int Date::daysInMonth(int month, int year) const {
    std::unordered_set<int> c31 = {1, 3, 5, 7, 8, 10, 12};
    std::unordered_set<int> c30 = {4, 6, 9, 11};

    if (month < 1 || month > 12) return 0;
    if (c31.find(month) != c31.end()) return 31;
    if (c30.find(month) != c30.end()) return 30;
    return year % 4 ? 29 : 28;
}

void Date::test_date(int day, int month, int year) const {
    if (year < 1 || year > 9999) {
        throw DateException(day, month, year, "year",
            "Year out of range [1; 9999]");
    }
    if (month < 1 || month > 12) {
        throw DateException(day, month, year, "month",
            "Month out of range [1; 12]");
    }
    if (day < 1 || day > daysInMonth(month, year)) {
        throw DateException(day, month, year, "day", "Day out of range [1; " +  std::to_string(daysInMonth(month, year)) +
                     "]");
    }
}

Date::Date(int day, int month, int year) : _day(day), _month(month), _year(year) {
    test_date(day, month, year);
}

Date::Date() : _day(1), _month(1), _year(1970) {}

int Date::getDay() const { return _day; }
int Date::getMonth() const { return _month; }
int Date::getYear() const { return _year; }

void Date::setDay(int day) {
    test_date(day, _month, _year);
    _day = day;
}
void Date::setMonth(int month) {
    test_date(_day, month, _year);
    _month = month;
}
void Date::setYear(int year) {
    test_date(_day, _month, year);
    _year = year;
}

std::string Date::dateToString() const {
    std::string res;
    res += (_day < 10 ? "0" : "") + std::to_string(_day) + ".";
    res += (_month < 10 ? "0" : "") + std::to_string(_month) + ".";
    res += std::to_string(_year);
    return res;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.dateToString();
    return os;
}