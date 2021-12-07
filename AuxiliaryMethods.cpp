#include "AuxiliaryMethods.h"


char AuxiliaryMethods :: getCharacter() {
    string providedCharacter = "";
    char character  = {0};

    while (true) {
        getline(cin, providedCharacter);

        if (providedCharacter.length() == 1) {
            character = providedCharacter[0];
            break;
        }
        cout << "This is not a single character. Please provide one more time." << endl;;
    }
    return character;
}
string AuxiliaryMethods :: changeFirstLetterToCapitalAndOtherToLowercase(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string AuxiliaryMethods :: getNumber(string text, int characterPosition) {
    string number = "";
    while(isdigit(text[characterPosition]) == true) {
        number += text[characterPosition];
        characterPosition ++;
    }
    return number;
}

int AuxiliaryMethods :: convertStringToInteger(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string AuxiliaryMethods :: convertIntegerToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods :: loadLine() {
    string input = "";
    getline(cin, input);
    return input;
}

string AuxiliaryMethods :: removeDashFromDate(string date) {

    string stringDateWithoutDash;

    for (int i = 0 ; i <= date.length(); i++) {
        if (date[i] != '-') {
            stringDateWithoutDash += date[i];
        }
    }
    return stringDateWithoutDash;
}

string AuxiliaryMethods :: addDashToDate(string date) {

    string stringDateWithDash;
    stringDateWithDash = date.insert (4,1,'-');
    stringDateWithDash = stringDateWithDash.insert (7,1,'-');

    return stringDateWithDash;
}

string AuxiliaryMethods::changeCommaToDot(string providedAmount) {
    string stringAmountWithoutComma = "";

    for (int i = 0 ; i <= providedAmount.length(); i++) {
        if (providedAmount[i] == ',') {
            providedAmount[i] = '.';
            stringAmountWithoutComma += providedAmount[i];
        } else
            stringAmountWithoutComma += providedAmount[i];
    }
    return stringAmountWithoutComma;
}

float AuxiliaryMethods::convertStringToFloat (string itemAmount) {
    float floatAmount = 0.0;
    floatAmount = atof(itemAmount.c_str());

    return floatAmount;
}
