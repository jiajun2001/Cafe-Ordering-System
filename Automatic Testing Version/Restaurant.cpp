#include "Restaurant.h"
#include <string>
#include <iostream>
using namespace std;

// Default constructor and size specific constructor

Restaurant::Restaurant(){
    numberOfTables = 5;
    occupiedTables = 0;
    restaurantTables = new Table*[5];
}

Restaurant::Restaurant(int pNumberOfTables){
    numberOfTables = pNumberOfTables;
    occupiedTables = 0;
    restaurantTables = new Table*[pNumberOfTables];
}

// Implementation of functions that create and clear tables
void Restaurant::createTable(){

    restaurantTables[occupiedTables] = new Table();
    occupiedTables++;
}

void Restaurant::clearSpecificTable(int tableNumber){
    // cout << "Cleared table with ID : " << restaurantTables[tableNumber-1]->getID() << endl;
    delete restaurantTables[tableNumber-1];
    for(int i = tableNumber - 1; i < occupiedTables; i++){
        if(i != occupiedTables - 1){
            restaurantTables[i] = restaurantTables[i+1];
        }else{
            restaurantTables[i] = NULL;
        }
    }
    occupiedTables--;
    // cout << "-------------------------------------------------------------------------------\n";
}

void Restaurant::clearAllTables(){
    for(int i = 0; i < occupiedTables; i++){
        delete restaurantTables[i];
        restaurantTables[i] = NULL;
    }
    occupiedTables = 0;
    cout << "All tables have been cleared !\n";
    // cout << "-------------------------------------------------------------------------------\n";
}

int Restaurant::getNumberOfOccupiedTables(){
    return occupiedTables;
}

int Restaurant::getNumberOfTables(){
    return numberOfTables;
}
Table* Restaurant::getTable(int tableNumber){
    return restaurantTables[tableNumber-1];
}

// Destructor function

Restaurant::~Restaurant(){
    for(int i = 0; i < occupiedTables; i++){
        delete restaurantTables[i];
    }
    delete[] restaurantTables;
}