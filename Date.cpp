#include "Date.h"

#include <sstream>

void Date::setDay(string newDay) {
    day = newDay;
}
void Date::setMonth(string newMonth) {
    month = newMonth;
}
void Date::setYear(string newYear) {
    year = newYear;
}
string Date :: getDate() {
    return date;
}
string Date::getDay() {
    return day;
}
string Date::getMonth() {
    return month;
}
string Date::getYear() {
    return year;
}


