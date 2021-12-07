#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>

#include "Item.h"
#include"FileWithIncomes.h"
#include"FileWithExpenses.h"
#include "DateManager.h"

using namespace std;

class ItemManager {
    const int ID_OF_LOGGED_USER;
    vector <Item> incomes;
    vector <Item> expenses;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;

    struct SortByDate;

    Item enterDataOfIncome();
    Item enterDataOfExpense();

public:
    ItemManager(string fileNameWithIncomes, string fileNameWithExpenses, int idOfLoggedUser)
        : fileWithIncomes(fileNameWithIncomes), fileWithExpenses(fileNameWithExpenses), ID_OF_LOGGED_USER(idOfLoggedUser) {
        incomes = fileWithIncomes.loadIncomesOfLoggedUserFromFile(ID_OF_LOGGED_USER);
        expenses = fileWithExpenses.loadExpensesOfLoggedUserFromFile(ID_OF_LOGGED_USER);
    };
    void addIncome();
    void addExpense();
    void displayBalanceForCurrentMonth();
    void displayBalanceForPreviousMonth();
    void displayBalanceForChosenPeriod();
    string getYearInStringFormatFromVector(int long long itemDate);
    string getMonthInStringFormatFromVector(int long long itemDate);
    int getIdOfNewIncome();
    int getIdOfNewExpense();
    bool checkIfProvidedAmountIsCorrect(string providedAmount);
};

#endif
