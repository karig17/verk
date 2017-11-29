#include "MainUI.h"

#include <iostream>
using namespace std;

MainUI::MainUI()
{
    //ctor
}


void MainUI::startUI() {
    cout << "Please select a branch" << endl;
    cout << "1)\tAdministration" << endl;
    cout << "2)\tSales" << endl;
    cout << "3)\tBaking" << endl;
    cout << "4)\tDelivery" << endl;
    cout << "5)\tExit/Quit" << endl;

    int userInput;
    bool validInput = false;

    while(!validInput) {
        cin >> userInput;
               if(userInput == '1') {

        } else if(userInput == '2') {

        } else if(userInput == '3') {

        } else if(userInput == '4') {

        } else if(userInput == '5') {

        } else {

        }
    }
}
