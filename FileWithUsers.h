#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "FileXML.h"
#include "Markup.h"


using namespace std;

class FileWithUsers : public FileXML {
    string fileNameWithUsers;

public:
    FileWithUsers(string fileNameWithUsers) : FileXML(fileNameWithUsers) {
    };
    void appendUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile(vector <User> users);
};

#endif
