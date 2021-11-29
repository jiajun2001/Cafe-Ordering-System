main: Menu.o Table.o Restaurant.o Main.o
	clang++ -o main Menu.o Table.o Restaurant.o Main.o

unitTesting: Menu.o Main2.o
	clang++ -o unit Menu.o Main2.o

Menu.o: Menu.cpp
	clang++ -c Menu.cpp

Table.o: Table.cpp
	clang++ -c Table.cpp

Restaurant.o: Restaurant.cpp
	clang++ -c Restaurant.cpp

Main.o: Main.cpp
	clang++ -c Main.cpp

UNmain: UNMenu.o UNTable.o UNRestaurant.o UNMain.o
	clang++ -o Main UNMenu.o UNTable.o UNRestaurant.o UNMain.o
	./Main

Main2.o: Main2.cpp
	clang++ -c Main2.cpp

UNMenu.o: UNMenu.cpp
	clang++ -c UNMenu.cpp

UNTable.o: UNTable.cpp
	clang++ -c UNTable.cpp

UNRestaurant.o: UNRestaurant.cpp
	clang++ -c UNRestaurant.cpp

UNMain.o: UNMain.cpp
	clang++ -c UNMain.cpp

customerDashboardSelection:
	./main < customerDashboardSelection.txt

customerViewMenus:
	./main < customerViewMenus.txt

customerAddAllItems:
	./main < customerAddAllItems.txt
	
customerViewOrder:
	./main < customerViewOrder.txt

customerRemoveAnItem:
	./main < customerRemoveAnItem.txt

customerClearAllSelections:
	./main < customerClearAllSelections.txt

customerRestaurantFull:
	./main < customerRestaurantFull.txt

customerDiscount:
	./main < customerDiscount.txt

managerNoPassword:
	./main < managerNoPassword.txt

managerClearSpecificTable:
	./main < managerClearSpecificTable.txt

managerClearAllTables:
	./main < managerClearAllTables.txt
