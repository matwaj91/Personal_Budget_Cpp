#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Item.h"
#include "AuxiliaryMethods.h"
#include "FileXML.h"


class FileWithExpenses : public FileXML {
    const string NAME_OF_FILE_WITH_EXPENSES;
    int idOfLoggedUser;
    vector <Item> expenses;

public:
    FileWithExpenses(string nameOfFileWithExpenses) : FileXML(nameOfFileWithExpenses) {};
    void addExpenseToFile(Item expense);
    vector <Item> loadExpensesOfLoggedUserFromFile(int idOfLoggedUser);
};

#endif
