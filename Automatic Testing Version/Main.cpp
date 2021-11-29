#include "Restaurant.h"
#include <iostream>
#include <ios>
#include <limits>
using namespace std;

int main(){

    // Creating the restaurant and dependent variables
    Restaurant* newRestaurant = new Restaurant();
    int menuSelection,firstSelection,itemNumber,typeOfUser,firstUserSelection;
    int mainSelection = 1,index = 1,beginningIndex = 1;
    string givenPassword = "nope";
    string password = "hello";
    int times=0; // Calculate the wrong password trial time

    // As beginning index is set to 1, while loop runs
    while(beginningIndex!=0){

        // Ask if the user is a manager or customer
        // cout << "Are you a customer or manager ?\n";
        // cout << 1 << " Customer\n";
        // cout << 2 << " Manager\n";
        // cout << "Please enter the number corresponding to the option : ";
        cin >> typeOfUser;

        // Input validation
        while(typeOfUser != 1 && typeOfUser != 2){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // cout << "-------------------------------------------------------------------------------\n";
            cout<<"Incorrect Selection!"<<endl;
            cout <<"Please select from the options given : ";
            cin >> typeOfUser;
        }
        // cout << "-------------------------------------------------------------------------------\n";

        // Behaviour if the user is a customer
        if(typeOfUser == 1){
            // cout << "Welcome to the cafe customer !\n";
            // cout << "-------------------------------------------------------------------------------\n";
            // cout << 1 << " Sit at a new table\n";
            // cout << 2 << " Exit\n";
            // cout << "Please enter the number corresponding to the option : ";
            cin >> firstUserSelection;
            while(typeOfUser != 1 && typeOfUser != 2){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                // cout <<"Please select from the options given : ";
                cin >> firstUserSelection;
            }
            // cout << "-------------------------------------------------------------------------------\n";

            // A new table is created, user is then able to order
            if(firstUserSelection == 1){
                if(newRestaurant->getNumberOfOccupiedTables() == newRestaurant->getNumberOfTables()){
                    index = 1;
                    cout << "Currently full ! Contact manager for help !\n";
                }else if(newRestaurant->getNumberOfOccupiedTables() != newRestaurant->getNumberOfTables()){
                    newRestaurant->createTable();
                    // Once user is done ordering, any further changes is done by the manager
                    while(index!= 0){
                        index = newRestaurant->getTable(newRestaurant->getNumberOfOccupiedTables())->operations();
                    }
                    // cout << "If you have any further changes to your order please contact the manager !\n";
                    index = 1;
                }
            }
        }
        // Behaviour if the user is a manager
        else if(typeOfUser == 2){
            // cout << "Please enter the password : ";
            cin >> givenPassword;
            // cout << "-------------------------------------------------------------------------------\n";

            // User has 3 tries to enter the manager password before being sent back to the user selection
            while(givenPassword!= password && givenPassword != "exit"){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Wrong password ! Please reenter password as 'exit' if you wish to return to the previous menu !\n";
                cout<<"You still have "<<2-times<<" time(s) for entering the password."<<endl;
                cout << "Please enter the password : ";
                cin >> givenPassword;
                times++;
                // cout << "-------------------------------------------------------------------------------\n";
                if(times==2 && givenPassword!=password)
                {
                    cout<<"Error! Please contact with the system administrator!"<<endl;
                    break;
                }
            }
            times=0;

            if(givenPassword == password){
                // As mainSelection is initially 1, loop runs
                while(mainSelection != 5 && mainSelection != 6){
                    // Print main menu
                    // cout << 1 << " Sit a new table\n";
                    // cout << 2 << " Manage order of a current table\n";
                    // cout << 3 << " Clear a specific table\n";
                    // cout << 4 << " Clear all tables\n";
                    // cout << 5 << " Exit\n";
                    // cout << 6 << " Close restaurant\n";
                    // cout << "What would you like to do : ";
                    cin >> mainSelection;
                    // cout << "-------------------------------------------------------------------------------\n";
                    // Bound checking for mainSelection
                    while(mainSelection < 1 || mainSelection > 6){
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        // cout << "Invalid choice, please enter 1, 2, 3, 4, 5 or 6 : ";
                        cin >> mainSelection;
                        // cout << "-------------------------------------------------------------------------------\n";
                    }
                    // Creating a new table
                    if(mainSelection == 1){
                        if(newRestaurant->getNumberOfOccupiedTables() != newRestaurant->getNumberOfTables()){
                            newRestaurant->createTable();;
                            // cout << 1 << " Yes\n";
                            // cout << 2 << " No\n";
                            // cout <<"Table created, would you like to continue ? ";
                            cin >> firstSelection;
                            // cout << "-------------------------------------------------------------------------------\n";
                            while(firstSelection < 1 || firstSelection > 2){
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Invalid choice ! Please choose again : ";
                                cin >> firstSelection;
                                // cout << "-------------------------------------------------------------------------------\n";
                            }
                            if(firstSelection == 1){
                                while(index != 0){
                                    index = newRestaurant->getTable(newRestaurant->getNumberOfOccupiedTables())->operations();
                                }
                            }
                        }else if(newRestaurant->getNumberOfOccupiedTables() == newRestaurant->getNumberOfTables()){
                            // cout << "Maximum number of tables allocated !\n";
                            // cout << "-------------------------------------------------------------------------------\n";
                        }
                        index = 1;
                    }
                    // Managing a specific table
                    else if(mainSelection == 2){
                        if(newRestaurant->getNumberOfOccupiedTables() == 0){
                            cout << "Currently no tables !\n";
                            cout << "-------------------------------------------------------------------------------\n";
                        }else if(newRestaurant->getNumberOfOccupiedTables() > 0){
                            cout << "Number" << "\t" << "Table\n";
                            for(int i = 0; i < newRestaurant->getNumberOfOccupiedTables() ;i++){
                                cout << i+1 << "\t" << "Table " << newRestaurant->getTable(i+1)->getID() << endl;
                            }
                            cout << newRestaurant->getNumberOfOccupiedTables() + 1 <<"\t"<<"Exit"<<endl;
                            // cout << "Which table would you like to manage : ";
                            cin >> firstSelection;
                            // cout << "-------------------------------------------------------------------------------\n";
                            while(firstSelection < 1 || firstSelection > newRestaurant->getNumberOfOccupiedTables() + 1){
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                // cout << "Invalid selection ! Please choose again : ";
                                cin >> firstSelection;
                                // cout << "-------------------------------------------------------------------------------\n";
                            }
                            while(index != 0){
                                if(firstSelection >= 1 && firstSelection <= newRestaurant->getNumberOfOccupiedTables())
                                {
                                    index = newRestaurant->getTable(firstSelection)->operations();
                                }
                                else
                                {
                                    // cout<<"Back to main menu"<<endl;
                                    index=0;
                                }
                            }
                        }
                        index = 1;
                    }
                    // Clearing a specific table
                    else if(mainSelection == 3){
                        if(newRestaurant->getNumberOfOccupiedTables() < 1){
                            cout << "Currently no tables !\n";
                            // cout << "-------------------------------------------------------------------------------\n";
                        }else{
                            cout << "Number" << "\t" << "Table\n";
                            for(int i = 0; i < newRestaurant->getNumberOfOccupiedTables() ;i++){
                                cout << i+1 << "\t" << "Table " << newRestaurant->getTable(i+1)->getID() << endl;
                            }
                            cout << newRestaurant->getNumberOfOccupiedTables() + 1 << "\t" << "Exit "<< endl;
                            // cout << "Which table do you wish to clear : ";
                            cin >> firstSelection;
                            cout << "-------------------------------------------------------------------------------\n";
                            while(firstSelection < 1 || firstSelection > newRestaurant->getNumberOfOccupiedTables() + 1){
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Invalid selection ! Please choose again : ";
                                cin >> firstSelection;
                                // cout << "-------------------------------------------------------------------------------\n";
                            }
                            if(firstSelection >=1 && firstSelection <= newRestaurant->getNumberOfOccupiedTables())
                            {
                                newRestaurant->clearSpecificTable(firstSelection);
                            }
                            else
                            {
                                // cout<<"Back to main menu"<<endl;
                            }
                        }
                        index = 1;
                    }
                    // Clearing all tables
                    else if(mainSelection == 4){
                        if(newRestaurant->getNumberOfOccupiedTables() < 1){
                            // cout << "Currently no tables !\n";
                            // cout << "-------------------------------------------------------------------------------\n";
                        }else{
                            // cout<<"Are you sure to clear all tables?"<<endl;
                            // cout<<"1 No"<<endl;
                            // cout<<"2 Yes"<<endl;
                            // cout << "What would you like to do : ";
                            int confirm;
                            cin >> confirm;
                            // Bounds checking
                            while(confirm != 1 && confirm != 2){
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                // cout << "Please enter a valid input !\n";
                                // cout << "What would you like to do : ";
                                cin >> confirm;
                            }
                            if(confirm==2)
                            {
                                // cout << "-------------------------------------------------------------------------------\n";
                                newRestaurant->clearAllTables();
                            }
                            else
                            {
                                // cout << "-------------------------------------------------------------------------------\n";
                                // cout<<"Back to main menu"<<endl;
                            }
                        }
                        index = 1;
                    }
                    // Exiting the manager mode
                    else if(mainSelection == 5){
                        // cout<<"Exiting the managing mode\n";
                        // cout << "-------------------------------------------------------------------------------\n";
                    }
                    else if(mainSelection == 6){
                        delete newRestaurant;
                        cout << "Goodbye !\n";
                        cout << "-------------------------------------------------------------------------------\n";
                        beginningIndex = 0;
                    }
                }
                mainSelection = 1;
            }
        }
    }
}
