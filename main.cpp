#include <iostream>

#include "PersonalBudget.h"


using namespace std;

int main() {
    vector <User> users;
    int idLoggedUser = 0;
    char choice;

    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");

    while (true) {
        if (personalBudget.checkIfUserIsLogged() == false) {
            choice = personalBudget.chooseOptionFromMainMenu();

            switch (choice) {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                personalBudget.logInUser();
                break;
            case '3':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in menu" << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = personalBudget.chooseOptionFromUserMenu();

            switch (choice) {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.displayBalanceForCurrentMonth();
                break;
            case '4':
                personalBudget.displayBalanceForPreviousMonth();
                break;
            case '5':
                personalBudget.displayBalanceForChosenPeriod();
                break;
            case '6':
                personalBudget.changePasswordOfLoggedUser();
                break;
            case '7':
                personalBudget.logOut();
                break;
            }
        }
    }
    return 0;
}



















