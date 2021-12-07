#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Item.h"
#include "AuxiliaryMethods.h"
#include "FileXML.h"


class FileWithIncomes : public FileXML {
    const string NAME_OF_FILE_WITH_INCOMES;
    int idOfLoggedUser;
    vector <Item> incomes;

public:
    FileWithIncomes(string nameOfFileWithIncomes) : FileXML(nameOfFileWithIncomes) {};
    void addIncomeToFile(Item income);
    vector <Item> loadIncomesOfLoggedUserFromFile(int idOfLoggedUser);
};

#endif
