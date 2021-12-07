#include "FileWithIncomes.h"
#include "Markup.h"

void FileWithIncomes :: addIncomeToFile(Item income) {
    CMarkup xml;
    string dateFromVector = "";
    string dateInCorrectFormat = "";
    string fileNameWithIncomes = FileXML :: getNameOfFile();
    bool fileExists = xml.Load(fileNameWithIncomes);
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem( "IncomeId", income.getItemId() );
    xml.AddElem( "UserId", income.getUserId() );
    dateFromVector = AuxiliaryMethods :: convertIntegerToString(income.getItemDate());
    dateInCorrectFormat= AuxiliaryMethods :: addDashToDate (dateFromVector);
    xml.AddElem( "Date", dateInCorrectFormat );
    xml.AddElem( "Item", income.getItemName() );
    xml.AddElem( "Amount", income.getItemAmount() );

    xml.Save(fileNameWithIncomes);

}
vector <Item> FileWithIncomes :: loadIncomesOfLoggedUserFromFile(int idLoggedUser) {
    Item item;
    vector <Item> incomes;
    string itemDateWithoutDashes = "";
    int itemDateInCorrectFormat = 0;
    CMarkup xml;
    string fileNameWithIncomes = FileXML :: getNameOfFile();
    bool fileExists = xml.Load(fileNameWithIncomes);

    if (fileExists == true) {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Income") == true) {
            xml.IntoElem();
            xml.FindElem("IncomeId");
            int itemId = atoi(xml.GetData().c_str());

            xml.FindElem("UserId");
            int userId = atoi(xml.GetData().c_str());
            if ( userId == idLoggedUser ) {
                item.setItemId(itemId);
                item.setUserId(userId);

                xml.FindElem("Date");
                string itemDate = xml.GetData();
                itemDateWithoutDashes = AuxiliaryMethods :: removeDashFromDate(itemDate);
                itemDateInCorrectFormat = AuxiliaryMethods :: convertStringToInteger(itemDateWithoutDashes);
                item.setItemDate(itemDateInCorrectFormat);

                xml.FindElem("Item");
                string incomeName = xml.GetData();
                item.setItemName(incomeName);

                xml.FindElem("Amount");
                string itemAmount = xml.GetData();
                item.setItemAmount(itemAmount);

                incomes.push_back(item);
            }
            xml.OutOfElem();
        }
    }
    return incomes;
}
