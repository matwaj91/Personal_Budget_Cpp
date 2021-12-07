#include"UserManager.h"
#include"FileWithUsers.h"

void UserManager::registerUser() {
    User user = enterDataOfNewUser();

    users.push_back(user);
    fileWithUsers.appendUserToFile(user);

    cout << endl << "Account has been successfully created" << endl << endl;
    system("pause");
}
User UserManager::enterDataOfNewUser() {
    User user;

    user.setUserId(getIdOfNewUser());

    string login, password, name, surname;

    do {
        cout << "Please provide login: ";
        cin >> login;
        user.setUserLogin(login);
    } while (checkIfLoginAlreadyExists(user.getUserLogin()) == true);

    cout << "Please provide password: ";
    cin >> password;
    user.setUserPassword(password);

    cout << "Please provide name: ";
    cin >> name;
    name = AuxiliaryMethods::changeFirstLetterToCapitalAndOtherToLowercase(name);
    user.setUserName(name);

    cout << "Please provide surname: ";
    cin >> surname;
    surname = AuxiliaryMethods::changeFirstLetterToCapitalAndOtherToLowercase(surname);
    user.setUserSurname(surname);

    return user;
}
int UserManager::getIdOfNewUser() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}
bool UserManager::checkIfLoginAlreadyExists(string login) {
    for(int i = 0; i < users.size(); i++) {
        if(users[i].getUserLogin() == login) {
            cout << endl << "This login is already being used" << endl << endl;
            system("pause");
            cout << endl;
            return true;
        }
    }
    return false;
}
void UserManager::loadUsersFromFile() {
    users = fileWithUsers.loadUsersFromFile();
}
int UserManager::logInUser() {
    User user;
    string login = "", password = "";

    cout << "Please provide login: ";
    cin >> login;
    user.setUserLogin(login);

    for(int i = 0; i < users.size();) {
        if (users[i].getUserLogin() == login) {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Please provide password. You have " << numberOfAttempts << " number of attempts: ";
                cin >> password;

                if (users[i].getUserPassword() == password) {
                    cout << endl << "You are logged in." << endl << endl;
                    system("pause");
                    idOfLoggedUser = users[i].getUserId();
                    return idOfLoggedUser;
                }
            }
            cout << endl << "Wrong password has been typed in 3 times.." << endl << endl;
            system("pause");
            return 0;
        }
        i++;
    }
    cout << "No user exists with such login" << endl << endl;
    system("pause");
    return 0;
}
void UserManager::changePasswordOfLoggedUser() {
    if (idOfLoggedUser > 0) {
        string newPassword = "";
        cout << "Please provide new Password: ";
        newPassword = AuxiliaryMethods::loadLine();

        for(vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
            if(itr -> getUserId() == idOfLoggedUser) {
                itr -> setUserPassword(newPassword);
                cout << "Password has been changed." << endl << endl;
                system("pause");
            }
        }
        fileWithUsers.saveAllUsersToFile(users);
    }
}
void UserManager::logOut() {
    idOfLoggedUser = 0;
}
char UserManager::chooseOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "3. End of program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";

    choice = AuxiliaryMethods::getCharacter();

    return choice;
}
char UserManager::chooseOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Display balance for current month" << endl;
    cout << "4. Display balance for previous month" << endl;
    cout << "5. Display balance for chosen period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";

    choice = AuxiliaryMethods::getCharacter();

    return choice;
}
bool UserManager::checkIfUserIsLogged() {
    if(idOfLoggedUser > 0)
        return true;
    else
        return false;
}
int UserManager::getIdOfLoggedUser() {
    return idOfLoggedUser;
}

