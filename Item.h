#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item {
    int itemId;
    int userId;
    int itemDate;
    string itemName;
    string itemAmount;

public:
    Item(int itemId = 0, int userId = 0, int itemDate = 0, string itemName = "", string itemAmount = "") {
        this->itemId = itemId;
        this->userId = userId;
        this->itemDate = itemDate;
        this->itemName = itemName;
        this->itemAmount = itemAmount;
    }

    void setItemId(int newId);
    void setUserId(int newIdUser);
    void setItemDate(int newItemDate);
    void setItemName(string newItemName);
    void setItemAmount(string newItemAmount);

    int getItemId();
    int getUserId();
    int getItemDate() const;
    string getItemName();
    string getItemAmount();
};

#endif
