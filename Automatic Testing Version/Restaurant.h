#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "Table.h"
#include <string>
using namespace std;

class Restaurant{

private:
    Table** restaurantTables;
    int numberOfTables;
    int occupiedTables; 
public:
    Restaurant();
    Restaurant(int pNumberOfTables);
    void createTable();
    void clearAllTables();
    void clearSpecificTable(int tableNumber);
    int getNumberOfOccupiedTables();
    int getNumberOfTables();
    Table* getTable(int tableNumber);
    ~Restaurant();
};
#endif