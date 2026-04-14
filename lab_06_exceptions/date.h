#pragma once

#include <string>
#include <stdexcept>


class DateException : public std::out_of_range {
private:
    int _day;
    int _month;
    int _year;
    std::string _errorField;

public:
    DateException(int day, int month, int year, const std::string& error_field, const std::string& error_msg);

    void print() const;

    int getDay() const;
    int getMonth() const;
    int getYear() const;
    std::string getErrorField() const;
};


class Date {
private:
    int _day;
    int _month;
    int _year;

    int daysInMonth(int month, int year) const;
    void test_date(int day, int month, int year) const;

public:
    Date(int day, int month, int year);
    Date();

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    std::string dateToString() const;

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};
