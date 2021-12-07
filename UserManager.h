#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"
#include "FileXML.h"

using namespace std;

class UserManager {
    int idOfLoggedUser;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User enterDataOfNewUser();
    int getIdOfNewUser();
    bool checkIfLoginAlreadyExists(string login);

public:
    UserManager(string fileNameWithUsers) : fileWithUsers(fileNameWithUsers) {
        idOfLoggedUser = 0;
        users = fileWithUsers.loadUsersFromFile();
    };
    bool checkIfUserIsLogged();
    void loadUsersFromFile();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    void registerUser();
    int logInUser();
    void changePasswordOfLoggedUser();
    void logOut();
    int getIdOfLoggedUser();
};

#endif
