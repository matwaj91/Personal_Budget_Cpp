#include "FileWithExpenses.h"
#include "Markup.h"

void FileWithExpenses :: addExpenseToFile(Item expense) {
    CMarkup xml;
    string dateFromVector = "";
    string dateInCorrectFormat = "";
    string fileNameWithExpenses = FileXML :: getNameOfFile();
    bool fileExists = xml.Load(fileNameWithExpenses);
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem( "ExpenseId", expense.getItemId() );
    xml.AddElem( "UserId", expense.getUserId() );
    dateFromVector = AuxiliaryMethods :: convertIntegerToString(expense.getItemDate());
    dateInCorrectFormat= AuxiliaryMethods :: addDashToDate (dateFromVector);
    xml.AddElem( "Date", dateInCorrectFormat );
    xml.AddElem( "Item", expense.getItemName() );
    xml.AddElem( "Amount", expense.getItemAmount() );

    xml.Save(fileNameWithExpenses);

}
vector <Item> FileWithExpenses :: loadExpensesOfLoggedUserFromFile(int idLoggedUser) {
    Item item;
    vector <Item> expenses;
    string itemDateWithoutDashes = "";
    int itemDateInCorrectFormat = 0;
    CMarkup xml;
    string fileNameWithExpenses = FileXML :: getNameOfFile();
    bool fileExists = xml.Load(fileNameWithExpenses);

    if (fileExists == true) {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Expense") == true) {
            xml.IntoElem();
            xml.FindElem("ExpenseId");
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
                string expenseName = xml.GetData();
                item.setItemName(expenseName);

                xml.FindElem("Amount");
                string expenseAmount = xml.GetData();
                item.setItemAmount(expenseAmount);

                expenses.push_back(item);
            }
            xml.OutOfElem();
        }
    }
    return expenses;
}
