#include "FileWithUsers.h"
#include "Markup.h"

void FileWithUsers :: appendUserToFile(User user) {
    CMarkup xml;
    string fileNameWithUsers = FileXML :: getNameOfFile();
    bool fileExists = xml.Load(fileNameWithUsers);
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem( "UserId", user.getUserId() );
    xml.AddElem( "Login", user.getUserLogin() );
    xml.AddElem( "Password", user.getUserPassword() );
    xml.AddElem( "Name", user.getUserName() );
    xml.AddElem( "Surname", user.getUserSurname() );

    xml.Save(fileNameWithUsers);

}
vector <User> FileWithUsers :: loadUsersFromFile() {
    User user;
    vector <User> users;

    CMarkup xml;
    string fileNameWithUsers = FileXML :: getNameOfFile();
    bool fileExists = xml.Load(fileNameWithUsers);

    if (fileExists == true) {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("User") == true) {

            xml.IntoElem();
            xml.FindElem( "UserId");
            int userId = atoi(xml.GetData().c_str());
            user.setUserId(userId);
            xml.FindElem( "Login");
            string login = xml.GetData();
            user.setUserLogin(login);
            xml.FindElem( "Password");
            string password = xml.GetData();
            user.setUserPassword(password);
            xml.FindElem( "Name");
            string userName = xml.GetData();
            user.setUserName(userName);
            xml.FindElem( "Surname");
            string userSurname = xml.GetData();
            user.setUserSurname(userSurname);
            users.push_back(user);

            xml.OutOfElem();
        }
    }
    return users;
}
void FileWithUsers :: saveAllUsersToFile(vector <User> users) {
    User user;
    CMarkup xml;
    string fileNameWithUsers = FileXML :: getNameOfFile();
    bool fileExists = xml.Load(fileNameWithUsers);

    if (fileExists == true) {
        xml.FindElem();
        xml.RemoveElem();
        xml.AddElem("Users");
        xml.FindElem();
        xml.IntoElem();
        for (int i = 0; i < users.size(); i++) {
            xml.AddElem("User");
            xml.IntoElem();
            xml.AddElem( "UserId", users[i].getUserId() );
            xml.AddElem( "Login", users[i].getUserLogin() );
            xml.AddElem( "Password", users[i].getUserPassword() );
            xml.AddElem( "Name", users[i].getUserName() );
            xml.AddElem( "Surname", users[i].getUserSurname() );
            xml.OutOfElem();
        }
        xml.Save(fileNameWithUsers);
    }
}

