#include "Item.h"

void Item::setItemId(int newId) {
    if(newId >= 0)
        itemId = newId;
}
void Item::setUserId(int newUserId) {
    if(newUserId >= 0)
        userId= newUserId;
}
void Item::setItemDate(int newDate) {
    if(newDate >= 0)
        itemDate = newDate;
}
void Item::setItemName(string newItemName) {
    itemName = newItemName;
}
void Item::setItemAmount(string newItemAmount) {
    itemAmount = newItemAmount;
}
int Item::getItemId() {
    return itemId;
}
int Item::getUserId() {
    return userId;
}
int Item::getItemDate() const {
    return itemDate;
}
string Item::getItemName() {
    return itemName;
}
string Item::getItemAmount() {
    return itemAmount;
}

