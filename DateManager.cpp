#include "DateManager.h"
#include "Windows.h"

int DateManager :: getCurrentDate() {
    int currentDate = 0;
    year = getCurrentYear();
    currentDate = (year * 10000);
    month = getCurrentMonth();
    currentDate += (month * 100);
    day = getCurrentDay();
    currentDate += day;

    return currentDate;
}

int DateManager :: getCurrentYear() {
    currentTime = time(NULL);
    nowLocal = *localtime(&currentTime);
    year = nowLocal.tm_year+1900;

    return year;
}

int DateManager :: getCurrentMonth() {
    string currentMonthInString = "";
    currentTime = time(NULL);
    nowLocal = *localtime(&currentTime);
    month = nowLocal.tm_mon+1;
    if(month > 0 && month < 10) {
        currentMonthInString = AuxiliaryMethods::convertIntegerToString(month);
        currentMonthInString = "0" + currentMonthInString;
        month = AuxiliaryMethods::convertStringToInteger(currentMonthInString);
    }
    return month;
}

int DateManager :: getPreviousMonth() {
    string previousMonthInString = "";
    currentTime = time(NULL);
    nowLocal = *localtime(&currentTime);
    month = nowLocal.tm_mon;
    if(month > 0 && month < 10) {
        previousMonthInString = AuxiliaryMethods::convertIntegerToString(month);
        previousMonthInString = "0" + previousMonthInString;
        month = AuxiliaryMethods::convertStringToInteger(previousMonthInString);
    }
    return month;
}

int DateManager :: getCurrentDay() {
    currentTime = time(NULL);
    nowLocal = *localtime(&currentTime);
    day = nowLocal.tm_mday;

    return day;
}

bool DateManager :: checkIfProvidedDateIsCorrect(string providedDate) {

    int year = (providedDate[0]-'0')*1000 + (providedDate[1]-'0')*100 + (providedDate[2]-'0')*10 + (providedDate[3]-'0');
    int month = (providedDate[5]-'0')*10 + (providedDate[6]-'0');
    int day = (providedDate[8]-'0')*10 + (providedDate[9]-'0');

    if (checkIfProvidedDateIsInCorrectFormat(providedDate) == false) {
        return false;
    } else if (checkIfYearIsCorrect(year) == false) {
        return false;
    } else if (checkIfMonthIsCorrect(month) == false || month > getCurrentMonth()) {
        return false;
    } else if (day >= 1 && day <= 31) {
        if (checkIfDayIsCorrect(day, month, year) == true) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }

    return true;
}

bool DateManager :: checkIfYearIsCorrect(int year) {

    if (year > getCurrentYear() || year < MINIMUM_YEAR) {
        return false;
    }
    return true;
}

bool DateManager :: checkIfMonthIsCorrect(int month) {
    if (month < 1 || month > 12) {
        return false;
    }
    return true;
}

bool DateManager :: checkIfDayIsCorrect (int day, int month, int year) {

    if (month == 2) {
        if ((checkIfYearIsLeapYear(year) == true) && (day == 29)) {
            return true;
        } else if (day >= 1 && day <= 28) {
            return true;
        } else if (day < 1 && day >= 30) {
            return false;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day >= 1 && day <= 30) {
            return true;
        } else
            return false;
    } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day >= 1 && day <= 31) {
            return true;
        } else
            return false;
    }
}

bool DateManager :: checkIfProvidedDateIsInCorrectFormat (string date) {

    if ((!date.size() == 10) || (!date[0] == 2) || (date[4] != '-') || (date[7] != '-'))
        return false;
    else
        return true;
}

bool DateManager :: checkIfYearIsLeapYear(int year) {
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        return true;
    } else
        return false;
}

bool DateManager::checkIfFirstProvidedDateIsEarlierOrDifferentThanSecond(int firstProvidedDate, int secondProvidedDate) {
    if(firstProvidedDate >= secondProvidedDate) {
        return false;
    } else
        return true;
}

















