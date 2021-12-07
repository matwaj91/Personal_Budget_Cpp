#ifndef FILEXML_H
#define FILEXML_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>


using namespace std;

class FileXML {
protected:
    const string NAME_OF_FILE;

public:
    FileXML(string nameOfFile) : NAME_OF_FILE(nameOfFile) {
    }
    string getNameOfFile();
};

#endif
