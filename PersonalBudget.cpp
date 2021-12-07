#include "PersonalBudget.h"

void PersonalBudget::registerUser() {
    userManager.registerUser();
}
void PersonalBudget::logInUser() {
    userManager.logInUser();
    if(userManager.checkIfUserIsLogged()) {
        itemManager = new ItemManager(FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPENSES, userManager.getIdOfLoggedUser());
    }
}
void PersonalBudget::changePasswordOfLoggedUser() {
    userManager.changePasswordOfLoggedUser();
}
void PersonalBudget::logOut() {
    userManager.logOut();
    delete itemManager;
    itemManager = NULL;
}
void PersonalBudget::addIncome() {
    if(userManager.checkIfUserIsLogged()) {
        itemManager->addIncome();
    } else {
        cout << "Please log in firstly in order to add income" << endl;
        system("pause");
    }
}
void PersonalBudget::addExpense() {
    if(userManager.checkIfUserIsLogged()) {
        itemManager->addExpense();
    } else {
        cout << "Please log in firstly in order to add expense" << endl;
        system("pause");
    }
}
void PersonalBudget::displayBalanceForCurrentMonth() {
    if(userManager.checkIfUserIsLogged()) {
        itemManager->displayBalanceForCurrentMonth();
    } else {
        cout << "Please log in firstly in order to display balance for current month" << endl;
        system("pause");
    }
}
void PersonalBudget::displayBalanceForPreviousMonth() {
    if(userManager.checkIfUserIsLogged()) {
        itemManager->displayBalanceForPreviousMonth();
    } else {
        cout << "Please log in firstly in order to display balance for previous month" << endl;
        system("pause");
    }
}
void PersonalBudget::displayBalanceForChosenPeriod() {
    if(userManager.checkIfUserIsLogged()) {
        itemManager->displayBalanceForChosenPeriod();
    } else {
        cout << "Please log in firstly in order to display balance for chosen period" << endl;
        system("pause");
    }
}
char PersonalBudget::chooseOptionFromMainMenu() {
    return userManager.chooseOptionFromMainMenu();
}
char PersonalBudget::chooseOptionFromUserMenu() {
    return userManager.chooseOptionFromUserMenu();
}
bool PersonalBudget::checkIfUserIsLogged() {
    if(userManager.checkIfUserIsLogged() > 0)
        return true;
    else
        return false;
}


