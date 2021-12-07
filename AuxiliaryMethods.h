#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class AuxiliaryMethods {
public:
    static char getCharacter();
    static string changeFirstLetterToCapitalAndOtherToLowercase(string text);
    static string loadLine();
    static string convertIntegerToString(int number);
    static int convertStringToInteger(string number);
    static int loadCharacter();
    static string removeDashFromDate (string date);
    static string addDashToDate (string date);
    static string changeCommaToDot(string amount);
    static string getNumber(string text, int characterPosition);
    static float convertStringToFloat (string itemAmount);
};

#endif
