#include "User.h"

void User::setUserId(int newId) {
    if(newId >= 0)
        userId = newId;
}
void User::setUserName(string newName) {
    userName = newName;
}
void User::setUserSurname(string newSurname) {
    userSurname = newSurname;
}
void User::setUserLogin(string newLogin) {
    userLogin = newLogin;
}
void User::setUserPassword(string newPassword) {
    userPassword = newPassword;
}
int User::getUserId() {
    return userId;
}
string User::getUserName() {
    return userName;
}
string User::getUserSurname() {
    return userSurname;
}
string User::getUserLogin() {
    return userLogin;
}
string User::getUserPassword() {
    return userPassword;
}

