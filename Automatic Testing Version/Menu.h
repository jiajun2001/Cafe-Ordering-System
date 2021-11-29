#ifndef MENU_H
#define MENU_H
#include <string>
using namespace std;

class Menu{
public:
    Menu();
    string getName();
    string getChoice(int currentSelection);
    string getDrinkChoice(int currentSecondSelection);
    int getReference();
    virtual void printSelection() = 0;
    virtual void printSpecificDetails() = 0;
    void printSelectionChoices();
    void printDrinkChoices();
    float getPrice();
    virtual ~Menu();
protected:
    string name;
    string choices[3];
    string drinkChoices[2];
    int reference;
    float price;
};

class CinnamonToast : public Menu{
public:
    CinnamonToast(string pFlavour);
    virtual void printSelection();
    virtual void printSpecificDetails();
    string flavour;
    virtual ~CinnamonToast();
};

class RamenNoodles : public Menu{
public:
    RamenNoodles(string pThickness);
    string thickness;
    virtual void printSelection();
    virtual void printSpecificDetails();
    virtual ~RamenNoodles();
};

class Salad : public Menu{
public:
    Salad(string pVegetableChoice);
    string vegetableChoice;
    virtual void printSelection();
    virtual void printSpecificDetails();
    virtual ~Salad();
};

class Bagel : public Menu{
public:
    Bagel(string pillingChoice);
    string fillingChoice;
    virtual void printSelection();
    virtual void printSpecificDetails();
    virtual ~Bagel();
};

class Croissant : public Menu{
public:
    Croissant(string pcroissantFlavour);
    string croissantFlavour;
    virtual void printSelection();
    virtual void printSpecificDetails();
    virtual ~Croissant();
};

class Burger : public Menu{
public:
    Burger(string pProteinSelection);
    string proteinSelection;
    virtual void printSelection();
    virtual void printSpecificDetails();
    virtual ~Burger();
};

class Espresso : public Menu{
public:
    Espresso(string pCoffeeIntensity, string pHotOrCold);
    string coffeeIntensity;
    string hotOrCold;
    void printDrinkChoices();
    virtual void printSelection();
    virtual void printSpecificDetails();
    virtual ~Espresso();
};

class Tea : public Menu{
public:
    Tea(string pTypeOfTea, string pHotOrCold);
    string typeOfTea;
    string hotOrCold;
    void printDrinkChoices();
    virtual void printSelection();
    virtual void printSpecificDetails();
    virtual ~Tea();
};

class Latte : public Menu{
public:
    Latte(string pSyrupChoice, string pHotOrCold);
    string syrupChoice;
    string hotOrCold;
    void printDrinkChoices();
    virtual void printSelection();
    virtual void printSpecificDetails();
    virtual ~Latte();
};

class ColdBrew : public Menu{
public:
    ColdBrew(string pMilkType);
    string milkType;
    virtual void printSelection();
    virtual void printSpecificDetails();
    virtual ~ColdBrew();
};
#endif
