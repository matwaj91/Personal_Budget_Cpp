#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <windows.h>
#include "AuxiliaryMethods.h"

#include "Date.h"

using namespace std;

class DateManager {
    time_t currentTime;
    struct tm nowLocal;

    int year, month, day;
    const int MINIMUM_YEAR = 2000;
    string providedDate;


public:
    int getCurrentDate();
    int getCurrentYear();
    int getCurrentMonth();
    int getPreviousMonth();
    int getCurrentDay();
    bool checkIfProvidedDateIsCorrect(string providedDate);
    bool checkIfProvidedDateIsInCorrectFormat(string providedDate);
    bool checkIfDayIsCorrect(int day, int month, int year);
    bool checkIfMonthIsCorrect(int month);
    bool checkIfYearIsCorrect(int year);
    bool checkIfYearIsLeapYear(int year);
    bool checkIfFirstProvidedDateIsEarlierThanSecond(int firstProvidedDate, int secondProvidedDate);
    bool checkIfProvidedDateRangeConsistsOfTwoDates(string providedStringDateRange);
};

#endif
