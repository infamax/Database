#include "date.h"


Date ParseDate(std::istream& is) {
    Date date;
    is >> date.year;
    is.ignore(1);
    is >> date.month;
    is.ignore(1);
    is >> date.day;
    return date;
}

std::string MakeStringFromDate(const Date& date) {
    std::string str = std::to_string(date.year) + "-";
    if (date.month <= 9) {
        str += "0" + std::to_string(date.month) + "-";
    } else {
        str += std::to_string(date.month) + "-";
    }
    if (date.day <= 9) {
        str += "0" + std::to_string(date.day);
    } else {
        str += std::to_string(date.day);
    }
    return str;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.year << "-";
    if (date.month <= 9) {
        os << 0 << date.month << "-";
    } else {
        os << date.month << "-";
    }
    if (date.day <= 9) {
        os << 0 << date.day;
    } else {
        os << date.day;
    }
    return os;
}

bool operator<(const Date& lhs, const Date& rhs) {
    return std::make_tuple(lhs.year, lhs.month, lhs.day) < std::make_tuple(rhs.year, rhs.month, rhs.day);
}

bool operator<=(const Date& lhs, const Date& rhs) {
    return std::make_tuple(lhs.year, lhs.month, lhs.day) <= std::make_tuple(rhs.year, rhs.month, rhs.day);
}

bool operator>(const Date& lhs, const Date& rhs) {
    return std::make_tuple(lhs.year, lhs.month, lhs.day) > std::make_tuple(rhs.year, rhs.month, rhs.day);
}

bool operator>=(const Date& lhs, const Date& rhs) {
    return std::make_tuple(lhs.year, lhs.month, lhs.day) >= std::make_tuple(rhs.year, rhs.month, rhs.day);
}

bool operator==(const Date& lhs, const Date& rhs) {
    return std::make_tuple(lhs.day, lhs.month, lhs.year) == std::make_tuple(rhs.day, rhs.month, rhs.year);
}

bool operator!=(const Date& lhs, const Date& rhs) {
    return std::make_tuple(lhs.day, lhs.month, lhs.year) != std::make_tuple(rhs.day, rhs.month, rhs.year);
}