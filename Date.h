#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date {
    string date;
    string day;
    string month;
    string year;

public:
    Date(string date = "") {
        this->date = date;
    }

    void setDay(string newDay);
    void setMonth(string newMonth);
    void setYear(string newYear);
    string getDate();
    string getDay();
    string getMonth();
    string getYear();
};

#endif
