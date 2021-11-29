#include "Menu.h"
#include <iostream>
using namespace std;
#include <string>

int main(void)
{
    Menu** cafeMenu = new Menu*[10];

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

    for(int i = 0; i < 10; i++)
    {
        cout << cafeMenu[i]->getName() << " " << cafeMenu[i]->getPrice()<<endl;
        cafeMenu[i]->printSpecificDetails();
        cout<<endl;
        cafeMenu[i]->printSelection();
        cout<<endl;
    }

    return 0;
}

