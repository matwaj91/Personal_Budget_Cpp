#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    int userId;
    string userName;
    string userSurname;
    string userLogin;
    string userPassword;

public:
    void setUserId(int newId);
    void setUserName(string newName);
    void setUserSurname(string newSurname);
    void setUserLogin(string newLogin);
    void setUserPassword(string newPassword);

    int getUserId();
    string getUserName();
    string getUserSurname();
    string getUserLogin();
    string getUserPassword();
};

#endif

