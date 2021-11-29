#include "Menu.h"
#include <iostream>
#include <string>
using namespace std;


// Implementation of the functions of the base class 'Menu'

Menu::Menu(){

}

// Implementation of basic 'get' functions

string Menu::getName(){
    return name;
}

float Menu::getPrice(){
    return price;
}


void Menu::printSelectionChoices(){
    // for(int i = 0; i < 3; i++){
    //     cout << i+1 << " " << choices[i] << endl;
    // }
}

void Menu::printDrinkChoices(){
    // for(int i = 0; i < 2; i++){
    //     cout << i+1 << " " << drinkChoices[i] << endl;
    // }
}

string Menu::getChoice(int currentFirstSelection){
    return choices[currentFirstSelection-1];
}

string Menu::getDrinkChoice(int currentSecondSelection){
    return drinkChoices[currentSecondSelection-1];
}

int Menu::getReference(){
    return reference;
}
// Destructor function

Menu::~Menu(){
    // cout << "Destroyed a menu item\n";
}

// Implementation of subclasses

// Implementation of methods for the 'CinnamonToast' class

CinnamonToast::CinnamonToast(string pFlavour):Menu(){
    flavour = pFlavour;
    reference = 1;
    name = "Cinnamon Toast";
    price = 9.9;
    choices[0] = "Original";
    choices[1] = "Apple";
    choices[2] = "Mocha";
}

void CinnamonToast::printSelection(){
    cout << "The bread that will be used to make the cinnamon toast will have a " << flavour << " flavour\n";
}

void CinnamonToast::printSpecificDetails(){
    cout << "Sliced bread, toasted, buttered, and sprinkled with a mix of cinnamon and sugar\n";
    cout << "We have different types of breads available to suit your flavour and they include :\n\n";
    for(int i = 0; i < 3; i++){
        cout << i+1 << " " << choices[i] << endl;
    }
    cout << "-------------------------------------------------------------------------------\n";
}

CinnamonToast::~CinnamonToast()
{

}

// Implementation of methods for the 'RamenNoodles' class

RamenNoodles::RamenNoodles(string pThickness):Menu(){
    thickness = pThickness;
    reference = 2;
    name = "Ramen Noodles";
    price = 14.99;
    choices[0] = "Thick";
    choices[1] = "Medium";
    choices[2] = "Thin";
}

void RamenNoodles::printSelection(){
    cout << "The noodle thickness selected is  " << thickness << "\n";
}

void RamenNoodles::printSpecificDetails(){
    cout << "These noodles is so delicious that you would keep coming back for more !\n";
    cout << "We have a few different types of noodles to suit your tastes :\n\n";
    for(int i = 0; i < 3; i++){
        cout << i+1  << " " << choices[i] << endl;
    }
    cout << "-------------------------------------------------------------------------------\n";
}

RamenNoodles::~RamenNoodles()
{

}

// Implementation of methods for the 'Salad' class

Salad::Salad(string pVegetableChoice){
    vegetableChoice = pVegetableChoice;
    name = "Vegetable Salad";
    reference = 3;
    price = 7.99;
    choices[0] = "Romaine";
    choices[1] = "Iceberg";
    choices[2] = "Mixed";
}

void Salad::printSelection(){
    cout << "The vegetable choice selected is " << vegetableChoice << endl;
}

void Salad::printSpecificDetails(){
    cout << "Delicious salad makes your life healthier!\n";
    cout << "Our salads are made with fresh vegetables that are replenished daily :\n\n";
    for(int i = 0; i < 3; i++){
        cout << i+1 << " " << choices[i] << endl;
    }
    cout << "-------------------------------------------------------------------------------\n";
}

Salad::~Salad()
{

}


// Implementation of methods for the 'Bagel' class

Bagel::Bagel(string pFillingChoice){
    name = "Bagel";
    reference = 4;
    price = 5.99;
    fillingChoice = pFillingChoice;
    choices[0] = "Cream Cheese";
    choices[1] = "Whipped Cream";
    choices[2] = "Chocolate";
}

void Bagel::printSelection(){
    cout << "The bagel will be filled with " << fillingChoice << "filling\n";
}

void Bagel::printSpecificDetails(){
    cout << "Freshly baked bagel with heart flavour\n";
    cout << "The bagels contain fillings, the choices that are available are :\n\n";
    for(int i = 0; i < 3; i++){
        cout << i+1 << " " << choices[i] << endl;
    }
    cout << "-------------------------------------------------------------------------------\n";
}

Bagel::~Bagel()
{

}

// Implementation of methods for the 'Croissant' class

Croissant::Croissant(string pCroissantFlavour){
    name = "Croissant";
    reference = 5;
    price = 4.99;
    croissantFlavour = pCroissantFlavour;
    choices[0] = "Original";
    choices[1] = "Vanilla";
    choices[2] = "Matcha";
}

void Croissant::printSelection(){
    cout << "Croissant has hints of " <<  croissantFlavour << " taste !";
}

void Croissant::printSpecificDetails(){
    cout << "Flaky crossaint baked with 100% buttery goodness !\n";
    cout << "We make our croissants with different flour mixes, thus we have flavours such as :\n\n";
    for(int i = 0; i < 3; i++){
        cout << i+1 << " " << choices[i] << endl;
    }
    cout << "-------------------------------------------------------------------------------\n";
}

Croissant::~Croissant()
{

}

// Implementation of methods for the 'Burger' class

Burger::Burger(string pProteinSelection){
    name = "Burger";
    reference = 6;
    price = 11.99;
    proteinSelection = pProteinSelection;
    choices[0] = "Lamb";
    choices[1] = "Chicken";
    choices[2] = "Beef";
}

void Burger::printSelection(){
    cout << "The protein choice you have selected is " << proteinSelection << endl;
}

void Burger::printSpecificDetails(){
    cout << "Flame grilled burger with multiple protein choices !\n";
    cout << "We have a variety of meat patty types to suit your tastes :\n\n";
    for(int i = 0; i < 3; i++){
        cout << i+1 << " " << choices[i] << endl;
    }
    cout << "-------------------------------------------------------------------------------\n";
}

Burger::~Burger()
{

}

// Implementation of methods for the 'Espresso' class

Espresso::Espresso(string pCoffeeIntensity, string pHotOrCold){
    name = "Espresso";
    reference = 7;
    price = 3.99;
    coffeeIntensity = pCoffeeIntensity;
    hotOrCold = pHotOrCold;
    choices[0] = "Strong";
    choices[1] = "Normal";
    choices[2] = "Light";
    drinkChoices[0] = "Hot";
    drinkChoices[1] = "Cold";
}

void Espresso::printSelection(){
    cout << "The intensity selected is " << coffeeIntensity << " coffee and will be served " << hotOrCold << endl;
}

void Espresso::printSpecificDetails(){
    cout << "A shot of espresso made from imported beans !\n";
    cout << "You also can have your coffee with different intensities :\n\n";
    for(int i = 0; i < 3; i++){
        cout << i+1 << " " << choices[i] << endl;
    }
    cout << endl << "You can also choose whether you want your drink " << drinkChoices[0] << " or " << drinkChoices[1] << endl;
    cout << "-------------------------------------------------------------------------------\n";
}

Espresso::~Espresso()
{

}

// Implementation of methods for the 'Tea' class

Tea::Tea(string pTypeOfTea, string pHotOrCold){
    name = "Tea";
    price = 3.99;
    reference = 8;
    typeOfTea = pTypeOfTea;
    hotOrCold = pHotOrCold;
    choices[0] = "Earl Grey";
    choices[1] = "English Breakfast";
    choices[2] = "Chamomile";
    drinkChoices[0] = "Hot";
    drinkChoices[1] = "Cold";

}

void Tea::printSelection(){
    cout << "Tea leaves selected are " << typeOfTea << " and will be served " << hotOrCold << endl;
}

void Tea::printSpecificDetails(){
    cout << "Freshly brewed tea with leaves of your choice !\n";
    cout << "Here are the tea leaf selections available :\n\n";
    for(int i = 0; i < 3; i++){
        cout << i+1 << " " << choices[i] << endl;
    }
    cout << endl << "You can also choose whether you want your drink " << drinkChoices[0] << " or " << drinkChoices[1] << endl;
    cout << "-------------------------------------------------------------------------------\n";
}

Tea::~Tea()
{

}

// Implementation of methods for the Latte class

Latte::Latte(string pSyrupChoice, string pHotOrCold){
    name = "Latte";
    reference = 9;
    price = 4.99;
    syrupChoice = pSyrupChoice;
    hotOrCold = pHotOrCold;
    choices[0] = "Original";
    choices[1] = "Hazelnut";
    choices[2] = "Vanilla";
    drinkChoices[0] = "Hot";
    drinkChoices[1] = "Cold";
}

void Latte::printSelection(){
    cout << syrupChoice << " flavoured latte will be served " << hotOrCold << endl;
}

void Latte::printSpecificDetails(){
    cout << "A drink that is a pleasant mixture of coffee and milk !\n";
    cout << "Our cafe's latte can be ordered with syrup, the flavours available include:\n\n";
    for(int i = 0; i < 3; i++){
        cout << i+1 << " " << choices[i] << endl;
    }
    cout << endl << "You can also choose whether you want your drink " << drinkChoices[0] << " or " << drinkChoices[1] << endl;
    cout << "-------------------------------------------------------------------------------\n";
}

Latte::~Latte()
{

}

// Implementation of methods for the 'ColdBrew' class

ColdBrew::ColdBrew(string pMilkType){
    name = "Cold Brew Coffee";
    reference = 10;
    price = 4.99;
    milkType = pMilkType;
    choices[0] = "no milk";
    choices[1] = "oatmeal milk";
    choices[2] = "almond milk";
}

void ColdBrew::printSelection(){
    cout << "Iced cold brew coffee served with " << milkType << endl;
}

void ColdBrew::printSpecificDetails(){
    cout << "Cold brew coffee served with the milk of choice\n";
    cout << "These are the milk choices available :\n\n";
    for(int i = 0; i < 3; i++){
        cout << i+1 << " " << choices[i] << endl;
    }
    cout << endl << "As per the name, this drink is only served cold !\n";
    cout << "-------------------------------------------------------------------------------\n";
}

ColdBrew::~ColdBrew()
{

}