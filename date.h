#pragma once

#include <iostream>
#include <tuple>

struct Date {
    int year;
    int month;
    int day;
};

Date ParseDate(std::istream& is);

std::ostream& operator<<(std::ostream& os, const Date& date);

std::string MakeStringFromDate(const Date& date);

bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
