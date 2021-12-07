#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "ItemManager.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;
    ItemManager *itemManager;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;

public:
    PersonalBudget(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpenses)
        : userManager(fileNameWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses) {
        itemManager = NULL;
    };
    ~PersonalBudget() {
        delete itemManager;
        itemManager = NULL;
    }
    bool checkIfUserIsLogged();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    void registerUser();
    void logInUser();
    void addIncome();
    void addExpense();
    void displayBalanceForCurrentMonth();
    void displayBalanceForPreviousMonth();
    void displayBalanceForChosenPeriod();
    void changePasswordOfLoggedUser();
    void logOut();
};


#endif
