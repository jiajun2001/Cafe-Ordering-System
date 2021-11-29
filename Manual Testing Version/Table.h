#ifndef TABLE_H
#define TABLE_H
#include "Menu.h"
#include <string>
using namespace std;
class Table{
public:
    Table();
    int getSelection(int pFirstSelection);
    int getSecondSelection(int pFirstSelection);
    int operations();
    int getID();
    void viewMenu();
    void viewDetailedMenu();
    void viewOrderList();
    void clearSelections();
    void addItem();
    void removeItem(int itemIndex);
    void enlargeCapacity();
    ~Table();
private:
    static int id;
    int tableID,numberOfItems,maxCapacity,itemNumber,menuSelection,detailSelection;
    int currentSelection,currentSecondSelection,numberOfDrinks,numberOfFood;
    float currentTotal;
    Menu** cafeMenu;
    Menu** orderList;
    Menu** backupOrderList;
};

#endif
