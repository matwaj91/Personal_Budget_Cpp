#include "ItemManager.h"

void ItemManager :: addIncome() {
    Item income = enterDataOfIncome();
    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);
    cout << endl << "Income has been added to the file" << endl << endl;
    system("pause");
}

void ItemManager :: addExpense() {
    Item expense = enterDataOfExpense();
    expenses.push_back(expense);
    fileWithExpenses.addExpenseToFile(expense);
    cout << endl << "Expense has been added to the file" << endl << endl;
    system("pause");
}

int ItemManager :: getIdOfNewIncome() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getItemId()+ 1;
}

int ItemManager :: getIdOfNewExpense() {
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getItemId()+ 1;
}

Item ItemManager :: enterDataOfIncome() {
    Item item;
    DateManager dateManager;
    string itemName, userSurname, providedStringDate, stringDateWithoutDash, providedAmount, stringAmountWithDotInsteadOfComma;
    int currentDate, intDateWithoutDash;
    char choice;

    int itemId = getIdOfNewIncome();
    item.setItemId(itemId);
    item.setUserId(ID_OF_LOGGED_USER);

    cout << "Do you want to add income with current date?" <<endl;
    cout << "If yes, please type in 'y', if you want to chose other date, please type in 'n': " << endl;

    choice = AuxiliaryMethods :: getCharacter();

    if (choice == 'y') {
        currentDate = dateManager.getCurrentDate();
        item.setItemDate(currentDate);
    } else if (choice == 'n') {
        do {
            cout << "Please provide date in format YYYY-MM-DD which is in the range from 2000-01-01 to the last day of current month: ";
            providedStringDate = AuxiliaryMethods :: loadLine();
        } while (dateManager.checkIfProvidedDateIsCorrect(providedStringDate) == false);
        stringDateWithoutDash = AuxiliaryMethods :: removeDashFromDate(providedStringDate);
        intDateWithoutDash = AuxiliaryMethods :: convertStringToInteger(stringDateWithoutDash);
        item.setItemDate(intDateWithoutDash);
    }
    cout << "Please provide income description: ";
    itemName = AuxiliaryMethods :: loadLine();
    item.setItemName(itemName);
    do {
        cout << "Please provide the amount: ";
        providedAmount = AuxiliaryMethods :: loadLine();
    } while (checkIfProvidedAmountIsCorrect(providedAmount) == false);
    stringAmountWithDotInsteadOfComma = AuxiliaryMethods::changeCommaToDot(providedAmount);
    item.setItemAmount(stringAmountWithDotInsteadOfComma);

    return item;
}

Item ItemManager :: enterDataOfExpense() {
    Item item;
    DateManager dateManager;
    string itemName, userSurname, providedStringDate, stringDateWithoutDash, providedAmount, stringAmountWithDotInsteadOfComma;
    int currentDate, intDateWithoutDash;
    char choice;

    int itemId = getIdOfNewExpense();
    item.setItemId(itemId);
    item.setUserId(ID_OF_LOGGED_USER);

    cout << "Do you want to add expense with current date?" <<endl;
    cout << "If yes, please type in 'y', if you want to chose other date, please type in 'n': " << endl;

    choice = AuxiliaryMethods :: getCharacter();

    if (choice == 'y') {
        currentDate = dateManager.getCurrentDate();
        item.setItemDate(currentDate);
    } else if (choice == 'n') {
        do {
            cout << "Please provide date in format YYYY-MM-DD which is in the range from 2000-01-01 to the last day of current month: ";
            providedStringDate = AuxiliaryMethods :: loadLine();
        } while (dateManager.checkIfProvidedDateIsCorrect(providedStringDate) == false);
        stringDateWithoutDash = AuxiliaryMethods :: removeDashFromDate(providedStringDate);
        intDateWithoutDash = AuxiliaryMethods :: convertStringToInteger(stringDateWithoutDash);
        item.setItemDate(intDateWithoutDash);
    }
    cout << "Please provide expense description: ";
    itemName = AuxiliaryMethods :: loadLine();
    item.setItemName(itemName);
    do {
        cout << "Please provide the amount: ";
        providedAmount = AuxiliaryMethods :: loadLine();
    } while (checkIfProvidedAmountIsCorrect(providedAmount) == false);
    stringAmountWithDotInsteadOfComma = AuxiliaryMethods :: changeCommaToDot(providedAmount);
    item.setItemAmount(stringAmountWithDotInsteadOfComma);

    return item;
}

bool ItemManager :: checkIfProvidedAmountIsCorrect(string providedAmount) {
    int sizeOfProvidedString = providedAmount.length();
    for (int i = 0 ; i < providedAmount.length(); i++) {
        if (isdigit(providedAmount[i]) || (providedAmount[i] == '.' && providedAmount[0] != '.' && providedAmount[sizeOfProvidedString-1] != '.') || (providedAmount[i] == ',' && providedAmount[0] != ',' && providedAmount[sizeOfProvidedString-1] != ','))
            continue;
        else {
            cout << "Incorrect data.";
            return false;
        }
    }
    return true;
}

struct ItemManager::SortByDate {
    bool operator()(Item const& L, Item const& R) {
        return L.getItemDate() < R.getItemDate();
    }
};

void ItemManager::displayBalanceForCurrentMonth() {
    sort(incomes.begin(), incomes.end(), SortByDate());

    DateManager dateManager;
    int currentMonth = 0;
    int currentYear = 0;
    int dateFromVector = 0;
    string currentMonthInStringFormat = "";
    string currentYearInStringFormat = "";
    string dateFromVectorInString = "";
    string dateWithDashes = "";
    float amount = 0;
    float totalAmountOfIncomes = 0;
    float totalAmountOfExpenses = 0;

    currentMonth = dateManager.getCurrentMonth();
    currentMonthInStringFormat = AuxiliaryMethods::convertIntegerToString(currentMonth);
    currentYear = dateManager.getCurrentYear();
    currentYearInStringFormat = AuxiliaryMethods::convertIntegerToString(currentYear);

    system("cls");
    cout << ">>> INCOMES <<<" << endl;

    for(int i = 0; i < incomes.size(); i++) {
        if((currentMonthInStringFormat == getMonthInStringFormatFromVector(incomes[i].getItemDate())) && (currentYearInStringFormat == getYearInStringFormatFromVector(incomes[i].getItemDate()))) {
            cout << endl << i + 1 << "." << "Income: " << incomes[i].getItemName() << endl;
            dateFromVector = incomes[i].getItemDate();
            dateFromVectorInString = AuxiliaryMethods::convertIntegerToString(dateFromVector);
            dateWithDashes = AuxiliaryMethods::addDashToDate(dateFromVectorInString);
            cout << "  Date: " << dateWithDashes << endl;
            cout << "  Amount: " << incomes[i].getItemAmount() << "zl" << endl;
        }
    }
    incomes.clear();
    incomes = fileWithIncomes.loadIncomesOfLoggedUserFromFile(ID_OF_LOGGED_USER);
    cout << endl;
    system("pause");

    sort(expenses.begin(), expenses.end(), SortByDate());

    cout << endl << ">>> EXPENSES <<<" << endl;

    for(int j = 0; j < expenses.size(); j++) {
        if((currentMonthInStringFormat == getMonthInStringFormatFromVector(expenses[j].getItemDate())) && (currentYearInStringFormat == getYearInStringFormatFromVector(expenses[j].getItemDate()))) {
            cout << endl << j + 1 << "." << "Expense: " << expenses[j].getItemName() << endl;
            dateFromVector = expenses[j].getItemDate();
            dateFromVectorInString = AuxiliaryMethods::convertIntegerToString(dateFromVector);
            dateWithDashes = AuxiliaryMethods::addDashToDate(dateFromVectorInString);
            cout << "  Date: " << dateWithDashes << endl;
            cout << "  Amount: " << expenses[j].getItemAmount() << "zl" << endl;
        }
    }
    expenses.clear();
    expenses = fileWithExpenses.loadExpensesOfLoggedUserFromFile(ID_OF_LOGGED_USER);
    cout << endl;
    system("pause");

    cout << endl << ">>> TOTAL INCOME <<<" << endl;

    for(int k = 0; k < incomes.size(); k++) {
        if((currentMonthInStringFormat == getMonthInStringFormatFromVector(incomes[k].getItemDate())) && (currentYearInStringFormat == getYearInStringFormatFromVector(incomes[k].getItemDate()))) {
            amount = AuxiliaryMethods::convertStringToFloat(incomes[k].getItemAmount());
            totalAmountOfIncomes += amount;
        }
        amount = 0;
    }
    cout << endl << "Total Income: " << totalAmountOfIncomes << "zl" << endl;
    cout << endl;
    system("pause");

    cout << endl << ">>> TOTAL EXPENSE <<<" << endl;

    for(int l = 0; l < expenses.size(); l++) {
        if((currentMonthInStringFormat == getMonthInStringFormatFromVector(expenses[l].getItemDate())) && (currentYearInStringFormat == getYearInStringFormatFromVector(expenses[l].getItemDate()))) {
            amount = AuxiliaryMethods::convertStringToFloat(expenses[l].getItemAmount());
            totalAmountOfExpenses += amount;
        }
    }
    cout << endl << "Total Expense: " << totalAmountOfExpenses << "zl" << endl;
    cout << endl;
    system("pause");

    float differenceBetweenIncomesAndExpenses = 0;

    differenceBetweenIncomesAndExpenses = (totalAmountOfIncomes - totalAmountOfExpenses);

    if((totalAmountOfIncomes - totalAmountOfExpenses) > 0)
        cout << endl << "There is a budget surplus in the current month: " << differenceBetweenIncomesAndExpenses << "zl." << endl;
    else
        cout << endl << "There is a budget deficit in the current month: " << abs(differenceBetweenIncomesAndExpenses) << "zl." << endl;
    cout << endl;
    system("pause");
}

string ItemManager::getYearInStringFormatFromVector(int long long dateFromVector) {
    int year = 0;
    string yearInStringFormat = "";

    for(int i  = 0; i < 4;  i++)
        year = dateFromVector /= 10;

    yearInStringFormat = AuxiliaryMethods::convertIntegerToString(year);

    return yearInStringFormat;
}

string ItemManager::getMonthInStringFormatFromVector(int long long dateFromVector) {
    int firstDigitOfMonth = 0;
    int secondDigitOfMonth = 0;
    string firstDigitInStringFormat = "";
    string secondDigitInStringFormat = "";
    string monthInStringFormat = "";

    firstDigitOfMonth = ((dateFromVector/1000) %10);
    secondDigitOfMonth = ((dateFromVector/100) %10);
    firstDigitInStringFormat = AuxiliaryMethods::convertIntegerToString(firstDigitOfMonth);
    secondDigitInStringFormat = AuxiliaryMethods::convertIntegerToString(secondDigitOfMonth);
    monthInStringFormat = firstDigitInStringFormat + secondDigitInStringFormat;

    return monthInStringFormat;
}

void ItemManager::displayBalanceForPreviousMonth() {
    sort(incomes.begin(), incomes.end(), SortByDate());

    DateManager dateManager;
    int previousMonth = 0;
    int currentYear = 0;
    int dateFromVector = 0;
    string previousMonthInStringFormat = "";
    string currentYearInStringFormat = "";
    string dateFromVectorInString = "";
    string dateWithDashes = "";
    float amount = 0;
    float totalAmountOfIncomes = 0;
    float totalAmountOfExpenses = 0;

    previousMonth = dateManager.getPreviousMonth();
    previousMonthInStringFormat = AuxiliaryMethods::convertIntegerToString(previousMonth);
    currentYear = dateManager.getCurrentYear();
    currentYearInStringFormat = AuxiliaryMethods::convertIntegerToString(currentYear);

    system("cls");
    cout << ">>> INCOMES <<<" << endl;

    for(int i = 0; i < incomes.size(); i++) {
        if((previousMonthInStringFormat == getMonthInStringFormatFromVector(incomes[i].getItemDate())) && (currentYearInStringFormat == getYearInStringFormatFromVector(incomes[i].getItemDate()))) {
            cout << endl << i + 1 << "." << "Income: " << incomes[i].getItemName() << endl;
            dateFromVector = incomes[i].getItemDate();
            dateFromVectorInString = AuxiliaryMethods::convertIntegerToString(dateFromVector);
            dateWithDashes = AuxiliaryMethods::addDashToDate(dateFromVectorInString);
            cout << "  Date: " << dateWithDashes << endl;
            cout << "  Amount: " << incomes[i].getItemAmount() << "zl" << endl;
        }
    }
    incomes.clear();
    incomes = fileWithIncomes.loadIncomesOfLoggedUserFromFile(ID_OF_LOGGED_USER);
    cout << endl;
    system("pause");

    sort(expenses.begin(), expenses.end(), SortByDate());

    cout << endl << ">>> EXPENSES <<<" << endl;

    for(int j = 0; j < expenses.size(); j++) {
        if((previousMonthInStringFormat == getMonthInStringFormatFromVector(expenses[j].getItemDate())) && (currentYearInStringFormat == getYearInStringFormatFromVector(expenses[j].getItemDate()))) {
            cout << endl << j + 1 << "." << "Expense: " << expenses[j].getItemName() << endl;
            dateFromVector = expenses[j].getItemDate();
            dateFromVectorInString = AuxiliaryMethods::convertIntegerToString(dateFromVector);
            dateWithDashes = AuxiliaryMethods::addDashToDate(dateFromVectorInString);
            cout << "  Date: " << dateWithDashes << endl;
            cout << "  Amount: " << expenses[j].getItemAmount() << "zl" << endl;
        }
    }
    expenses.clear();
    expenses = fileWithExpenses.loadExpensesOfLoggedUserFromFile(ID_OF_LOGGED_USER);
    cout << endl;
    system("pause");

    cout << endl << ">>> TOTAL INCOME <<<" << endl;

    for(int k = 0; k < incomes.size(); k++) {
        if((previousMonthInStringFormat == getMonthInStringFormatFromVector(incomes[k].getItemDate())) && (currentYearInStringFormat == getYearInStringFormatFromVector(incomes[k].getItemDate()))) {
            amount = AuxiliaryMethods::convertStringToFloat(incomes[k].getItemAmount());
            totalAmountOfIncomes += amount;
        }
        amount = 0;
    }
    cout << endl << "Total Income: " << totalAmountOfIncomes << "zl" << endl;
    cout << endl;
    system("pause");

    cout << endl << ">>> TOTAL EXPENSE <<<" << endl;

    for(int l = 0; l < expenses.size(); l++) {
        if((previousMonthInStringFormat == getMonthInStringFormatFromVector(expenses[l].getItemDate())) && (currentYearInStringFormat == getYearInStringFormatFromVector(expenses[l].getItemDate()))) {
            amount = AuxiliaryMethods::convertStringToFloat(expenses[l].getItemAmount());
            totalAmountOfExpenses += amount;
        }
    }
    cout << endl << "Total Expense: " << totalAmountOfExpenses << "zl" << endl;
    cout << endl;
    system("pause");

    float differenceBetweenIncomesAndExpenses = 0;

    differenceBetweenIncomesAndExpenses = (totalAmountOfIncomes - totalAmountOfExpenses);

    if((totalAmountOfIncomes - totalAmountOfExpenses) > 0)
        cout << endl << "There is a budget surplus in the previous month: " << differenceBetweenIncomesAndExpenses << "zl." << endl;
    else
        cout << endl << "There is a budget deficit in the previous month: " << abs(differenceBetweenIncomesAndExpenses) << "zl." << endl;
    cout << endl;
    system("pause");
}

void ItemManager::displayBalanceForChosenPeriod() {
    DateManager dateManager;
    Item item;
    string providedStringDateRange = "";
    string firstProvidedStringDate = "";
    string secondProvidedStringDate = "";
    string firstDateWithoutDashes = "";
    string secondDateWithoutDashes = "";
    string dateFromVectorInString = "";
    string dateWithDashes = "";
    int dateFromVector = 0;
    int firstProvidedIntegerDate = 0;
    int secondProvidedIntegerDate = 0;
    float amount = 0;
    float totalAmountOfIncomes = 0;
    float totalAmountOfExpenses = 0;

    sort(incomes.begin(), incomes.end(), SortByDate());

    do {
        cout << "Please provide two dates in format 'YYYY-MM-DD YYYY-MM-DD'(earlier date and then later date). They should be in the range from 2000-01-01 to the last day of the current month: ";
        providedStringDateRange  = AuxiliaryMethods::loadLine();
        firstProvidedStringDate = providedStringDateRange.substr(0,10);
        secondProvidedStringDate = providedStringDateRange.substr(11,20);
        firstDateWithoutDashes = AuxiliaryMethods :: removeDashFromDate(firstProvidedStringDate);
        secondDateWithoutDashes = AuxiliaryMethods :: removeDashFromDate(secondProvidedStringDate);
        firstProvidedIntegerDate = AuxiliaryMethods::convertStringToInteger(firstDateWithoutDashes);
        secondProvidedIntegerDate = AuxiliaryMethods::convertStringToInteger(secondDateWithoutDashes);

    } while ((dateManager.checkIfProvidedDateIsCorrect(firstProvidedStringDate) == false) || (dateManager.checkIfProvidedDateIsCorrect(secondProvidedStringDate) == false) || (dateManager.checkIfFirstProvidedDateIsEarlierOrDifferentThanSecond(firstProvidedIntegerDate, secondProvidedIntegerDate)  == false));

    system("cls");
    cout << ">>> INCOMES <<<" << endl;

    for(int i = 0; i < incomes.size(); i++) {
        if(firstProvidedIntegerDate <= incomes[i].getItemDate() && (secondProvidedIntegerDate >= incomes[i].getItemDate())) {
            cout << endl << i + 1 << "." << "Income: " << incomes[i].getItemName() << endl;
            dateFromVector = incomes[i].getItemDate();
            dateFromVectorInString = AuxiliaryMethods::convertIntegerToString(dateFromVector);
            dateWithDashes = AuxiliaryMethods::addDashToDate(dateFromVectorInString);
            cout << "  Date: " << dateWithDashes << endl;
            cout << "  Amount: " << incomes[i].getItemAmount() << "zl" << endl;
        }
    }
    incomes.clear();
    incomes = fileWithIncomes.loadIncomesOfLoggedUserFromFile(ID_OF_LOGGED_USER);
    cout << endl;
    system("pause");

    sort(expenses.begin(), expenses.end(), SortByDate());

    cout << endl << ">>> EXPENSES <<<" << endl;

    for(int j = 0; j < expenses.size(); j++) {
        if(firstProvidedIntegerDate <= expenses[j].getItemDate() && (secondProvidedIntegerDate >= expenses[j].getItemDate())) {
            cout << endl << j + 1 << "." << "Expense: " << expenses[j].getItemName() << endl;
            dateFromVector = expenses[j].getItemDate();
            dateFromVectorInString = AuxiliaryMethods::convertIntegerToString(dateFromVector);
            dateWithDashes = AuxiliaryMethods::addDashToDate(dateFromVectorInString);
            cout << "  Date: " << dateWithDashes << endl;
            cout << "  Amount: " << expenses[j].getItemAmount() << "zl" << endl;
        }
    }
    expenses.clear();
    expenses = fileWithExpenses.loadExpensesOfLoggedUserFromFile(ID_OF_LOGGED_USER);
    cout << endl;
    system("pause");
    cout << endl << ">>> TOTAL INCOME <<<" << endl;

    for(int k = 0; k < incomes.size(); k++) {
        if((firstProvidedIntegerDate <= incomes[k].getItemDate()) && (secondProvidedIntegerDate >= incomes[k].getItemDate())) {
            amount = AuxiliaryMethods::convertStringToFloat(incomes[k].getItemAmount());
            totalAmountOfIncomes += amount;
        }
        amount = 0;
    }
    cout << endl << "Total Income: " << totalAmountOfIncomes << "zl" << endl;
    cout << endl;
    system("pause");

    cout << endl << ">>> TOTAL EXPENSE <<<" << endl;

    for(int l = 0; l < expenses.size(); l++) {
        if((firstProvidedIntegerDate <= expenses[l].getItemDate()) && (secondProvidedIntegerDate >= expenses[l].getItemDate())) {
            amount = AuxiliaryMethods::convertStringToFloat(expenses[l].getItemAmount());
            totalAmountOfExpenses += amount;
        }
    }
    cout << endl << "Total Expense: " << totalAmountOfExpenses << "zl" << endl;
    cout << endl;
    system("pause");

    float differenceBetweenIncomesAndExpenses = 0;

    differenceBetweenIncomesAndExpenses = (totalAmountOfIncomes - totalAmountOfExpenses);

    if((totalAmountOfIncomes - totalAmountOfExpenses) > 0)
        cout << endl << "There is a budget surplus in the chosen  period: " << differenceBetweenIncomesAndExpenses << "zl." << endl;
    else
        cout << endl << "There is a budget deficit in the chosen  period: " << abs(differenceBetweenIncomesAndExpenses) << "zl." << endl;
    cout << endl;
    system("pause");
}









