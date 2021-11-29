#include "Table.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <limits>
using namespace std;

Table::Table(){
    orderList = new Menu*[5];
    maxCapacity = 5;
    numberOfItems = 0;
    numberOfDrinks = 0;
    numberOfFood = 0;
    id++;
    tableID = id;
    // Default menu
    cafeMenu = new Menu*[10];
    cafeMenu[0] = new CinnamonToast("default");
    cafeMenu[1] = new RamenNoodles("default");
    cafeMenu[2] = new Salad("default");
    cafeMenu[3] = new Bagel("default");
    cafeMenu[4] = new Croissant("default");
    cafeMenu[5] = new Burger("default");
    cafeMenu[6] = new Espresso("default","default");
    cafeMenu[7] = new Tea("default","default");
    cafeMenu[8] = new Latte("default","default");
    cafeMenu[9] = new ColdBrew("default");

}

// Implementation of static int

int Table::id = 0;

// Get selections for each choice relating to food option

int Table::getSelection(int pFirstSelection){
    cafeMenu[pFirstSelection-1]->printSelectionChoices();
    // cout << "Enter the number of your selection : ";
    cin >> currentSelection;
    // cout << "-------------------------------------------------------------------------------\n";
    while(currentSelection != 1 && currentSelection != 2 && currentSelection != 3){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid selection, please choose again : ";
        cin >> currentSelection;
        cout << "-------------------------------------------------------------------------------\n";
    }
    return currentSelection;
}

// Get selection for hot/cold preference in drinks

int Table::getSecondSelection(int pFirstSelection){
    cafeMenu[pFirstSelection-1]->printDrinkChoices();
    // cout << "Enter the number of your selection : ";
    cin >> currentSecondSelection;
    // cout << "-------------------------------------------------------------------------------\n";
    while(currentSecondSelection != 1 && currentSecondSelection != 2){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid selection, please choose again : ";
        cin >> currentSecondSelection;
        cout << "-------------------------------------------------------------------------------\n";
    }
    return currentSecondSelection;
}

// View menu with descriptions

// void Table::viewDetailedMenu(){
//     for(int i = 0; i <10; i++){
//         cout << i+1 << " " << cafeMenu[i]->getName() << "\t" << cafeMenu[i]->getPrice() << endl << endl;
//         cout << cafeMenu[i]->getDescription() << "\n";
//         cout << "-------------------------------------------------------------------------------\n";
//     }
// }

// View basic menu

void Table::viewMenu(){
    cout << "Index\t" << "Price\t" << "Name\n";
    for(int i = 0; i <10; i++){
        cout << i+1 << "\t" <<  cafeMenu[i]->getPrice() << "\t" << cafeMenu[i]->getName() <<endl;
    }
    cout << "-------------------------------------------------------------------------------\n";
}

// View currently ordered items and total
// If there is at least one food and one drink ordered, a 10% discount applies

void Table::viewOrderList(){
    cout << "Currently ordered items :\n\n";
    currentTotal = 0;
    if(numberOfFood == 0 || numberOfDrinks == 0){
        for(int i = 0; i < numberOfItems; i++){
            cout << i+1 << "\t" <<  orderList[i]->getPrice()<< "\t" << orderList[i]->getName() << "\n";
            currentTotal = currentTotal +  orderList[i]->getPrice();
        }
        cout << "The current total is   " << ": " << setprecision(2) << fixed << currentTotal << endl;
        cout << "Current total with tax " << ": " << setprecision(2) << fixed << currentTotal*1.06 << endl;
        cout << "-------------------------------------------------------------------------------\n";
    } else {
        for(int i = 0; i < numberOfItems; i++){
            cout << i+1 << "\t" <<  orderList[i]->getPrice()<< "\t" << orderList[i]->getName() << "\n";
            currentTotal = currentTotal +  orderList[i]->getPrice();
        }
        currentTotal = currentTotal*0.9;
        cout << "Your order is eligible for 10\% off, applies to order total !\n";
        cout << "The current total is   " << ": " << setprecision(2) << fixed << currentTotal << endl;
        cout << "Current total with tax " << ": " << setprecision(2) << fixed << currentTotal*1.06 << endl;
        cout << "-------------------------------------------------------------------------------\n";
    }

    // // cout << "\nWould you like to view what choices you have made for each order ?\n\n";
    // // cout << "1 Yes\n2 No\n\n";
    // // cout << "Please enter your choice : ";
    // cin >> currentSelection;
    // // cout << "-------------------------------------------------------------------------------\n";
    // while(currentSelection != 1 && currentSelection != 2){
    //     cin.clear();
    //     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //     cout << "Invalid choice ! Please enter again : ";
    //     cin >> currentSelection;
    //     cout<<"\n";
    //     // cout << "-------------------------------------------------------------------------------\n";
    // }
    // if(currentSelection == 1){
    //     for(int i  = 0; i < numberOfItems; i++){
    //         cout << i+1 << "\t" <<  orderList[i]->getPrice()<< "\t" << orderList[i]->getName() << "\n\n";
    //         orderList[i]->printSelection();
    //         cout << "\n";
    //     }
    //     // cout << "-------------------------------------------------------------------------------\n";
    // }
}

// Clear current selections

void Table::clearSelections(){
    for(int i = 0; i < numberOfItems; i++){
        delete orderList[i];
        orderList[i] = NULL;
    }
    delete[] orderList;
    maxCapacity = 5;
    orderList = new Menu*[maxCapacity];
    numberOfItems = 0;
    numberOfFood = 0;
    numberOfDrinks = 0;
    cout << "The table has been cleared !\n";
    cout << "-------------------------------------------------------------------------------\n";
}

// Adding item function

void Table::addItem(){
    // viewMenu();
    // cout << "Please choose from one of the options given : ";
    cin >> currentSelection;
    // cout << "-------------------------------------------------------------------------------\n";
    while(currentSelection < 1 || currentSelection > 10){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid selection ! Please select again : ";
        cin >> currentSelection;
        cout << "-------------------------------------------------------------------------------\n";
    }
    // Keeping track of number of food type items and drink type items ordered
    if(currentSelection <= 6){
        numberOfFood++;
    }else if(currentSelection > 6){
        numberOfDrinks++;
    }
    // For any type of item selected, the corresponding option choices are obtained before creating the object
    switch(currentSelection){
        case 1:
            currentSelection = getSelection(currentSelection);
            orderList[numberOfItems] = new CinnamonToast(cafeMenu[0]->getChoice(currentSelection));
            break;
        case 2:
            currentSelection = getSelection(currentSelection);
            orderList[numberOfItems] = new RamenNoodles(cafeMenu[1]->getChoice(currentSelection));
            break;
        case 3:
            currentSelection = getSelection(currentSelection);
            orderList[numberOfItems] = new Salad(cafeMenu[2]->getChoice(currentSelection));
            break;
        case 4:
            currentSelection = getSelection(currentSelection);
            orderList[numberOfItems] = new Bagel(cafeMenu[3]->getChoice(currentSelection));
            break;
        case 5:
            currentSelection = getSelection(currentSelection);
            orderList[numberOfItems] = new Croissant(cafeMenu[4]->getChoice(currentSelection));
            break;
        case 6:
            currentSelection = getSelection(currentSelection);
            orderList[numberOfItems] = new Burger(cafeMenu[5]->getChoice(currentSelection));
            break;
        case 7:
            currentSecondSelection = getSecondSelection(currentSelection);
            currentSelection = getSelection(currentSelection);
            orderList[numberOfItems] = new Espresso(cafeMenu[6]->getChoice(currentSelection),cafeMenu[6]->getDrinkChoice(currentSecondSelection));
            break;
        case 8:
            currentSecondSelection = getSecondSelection(currentSelection);
            currentSelection = getSelection(currentSelection);
            orderList[numberOfItems] = new Tea(cafeMenu[7]->getChoice(currentSelection),cafeMenu[7]->getDrinkChoice(currentSecondSelection));
            break;
        case 9:
            currentSecondSelection = getSecondSelection(currentSelection);
            currentSelection = getSelection(currentSelection);
            orderList[numberOfItems] = new Latte(cafeMenu[8]->getChoice(currentSelection),cafeMenu[8]->getDrinkChoice(currentSecondSelection));
            break;
        case 10:
            currentSelection = getSelection(currentSelection);
            orderList[numberOfItems] = new ColdBrew(cafeMenu[9]->getChoice(currentSelection));
            break;
    }
    numberOfItems++;
}

// Removing item function

void Table::removeItem(int itemIndex){
    if(orderList[itemIndex-1]->getReference() <= 6){
        numberOfFood--;
    }else if(orderList[itemIndex-1]->getReference() > 6){
        numberOfDrinks--;
    }
    for(int i = (itemIndex - 1); i < numberOfItems; i++){
        if(i!=(numberOfItems-1)){
            orderList[i] = orderList[i+1];
        }else{
            orderList[i] = NULL;
        }
    }
    numberOfItems--;
    // cout << "-------------------------------------------------------------------------------\n";
}

// Once orders reach their maximum amount, double capacity of a table

void Table::enlargeCapacity(){
    backupOrderList = new Menu*[maxCapacity*2];
    maxCapacity = maxCapacity*2;
    for(int i = 0; i < numberOfItems; i++){
        backupOrderList[i] = orderList[i];
    }
    delete[] orderList;
    orderList = backupOrderList;
}

// Menu of operations for a table

int Table::operations(){
    if(numberOfItems == maxCapacity){
        enlargeCapacity();
    }
    // cout << "Please choose from the following options !\n";
    // cout << 1 << "\t" << "View the menu\n";
    // cout << 2 << "\t" << "View detailed menu\n";
    // cout << 3 << "\t" << "Add an item to order\n";
    // cout << 4 << "\t" << "Remove an item from order\n";
    // cout << 5 << "\t" << "Clear all selections\n";
    // cout << 6 << "\t" << "View current order\n";
    // cout << 7 << "\t" << "Exit\n";
    // cout << "Please choose an option by entering the number corresponding to the option : ";
    cin >> menuSelection;
    // cout << "-------------------------------------------------------------------------------\n";
    while(menuSelection < 1 || menuSelection > 7){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"Incorrect Selection!"<<endl;
        cout << "Please choose a number between 1 and 7 : ";
        cin >> menuSelection;
    }
    switch(menuSelection){
        case 1:
            viewMenu();
            return 1;
            break;
        case 2:
            // viewMenu();
            // cout << "Please select the item which you want to view details of : ";
            cin >> detailSelection;
            while(detailSelection < 1 || detailSelection > 10){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid choice, please reenter !\n";
                cout << "Please select the item which you want to view details of : ";
                cin >> detailSelection;
            }
            cout << endl;
            cafeMenu[detailSelection-1]->printSpecificDetails();
            return 1;
            break;
        case 3:
            addItem();
            return 1;
            break;
        case 4:
            if(numberOfItems < 1){
                cout << "No item to remove !\n";
                // cout << "-------------------------------------------------------------------------------\n";
                return 1;
            }
            viewOrderList();
            // cout << "Select the item index to remove : ";
            cin >> itemNumber;
            while(itemNumber < 1 || itemNumber > numberOfItems){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid choice, please reenter !\n";
                cout << "Select the item index to remove : ";
                cin >> itemNumber;
            }
            removeItem(itemNumber);
            return 1;
            break;
        case 5:
            clearSelections();
            return 1;
            break;
        case 6:
            viewOrderList();
            // cout << "\nWould you like to view what choices you have made for each order ?\n\n";
            // cout << "1 Yes\n2 No\n\n";
            // cout << "Please enter your choice : ";
            cin >> currentSelection;
            // cout << "-------------------------------------------------------------------------------\n";
            while(currentSelection != 1 && currentSelection != 2){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid choice ! Please enter again : ";
                cin >> currentSelection;
                cout<<"\n";
                // cout << "-------------------------------------------------------------------------------\n";
            }
            if(currentSelection == 1){
                for(int i  = 0; i < numberOfItems; i++){
                    cout << i+1 << "\t" <<  orderList[i]->getPrice()<< "\t" << orderList[i]->getName() << "\n\n";
                    orderList[i]->printSelection();
                    cout << "\n";
                }
                // cout << "-------------------------------------------------------------------------------\n";
            }
                return 1;
                break;
        case 7:
            // cout<<"Returning to previous menu\n";
            return 0;
            break;
    }
    return 0;
}

int Table::getID(){
    return tableID;
}

// Destructor function

Table::~Table(){
    for(int i =0; i < numberOfItems; i++){
        delete orderList[i];
    }
    delete[] orderList;
    // cout << "Destroyed a table !\n";
}
