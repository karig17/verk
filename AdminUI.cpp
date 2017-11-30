#include "AdminUI.h"

AdminUI::AdminUI()
{
    //ctor
}

AdminUI::~AdminUI()
{
    //dtor
}

void AdminUI::startUp() {
    cout << "type 1 to add size" << endl;
    cout << "type 2 to add topping" << endl;
    cout << "type 3 to add pizza to menu" << endl;
    cout << "type 4 to add extras" << endl;
    cout << "type 5 to add prize" << endl;
    cout << "type 6 to add pizzaplace" << endl;
    cout << "type q to add quit" << endl;
    char c;

    while(c != 'q') {
        cin >> c;
            if (c == '1') {

            }
            if (c == '2') {
                     ofstream fout;

    Topping topping;

    int toppingMasterSize = topping.getLines();

    Topping* toppingMaster = topping.readFile();

    for(int i = 0; i < toppingMasterSize; i++) {
        cout << (i + 1) << ")" << toppingMaster[i];

    }
    char userInput;
    do {
        userInput = 'n';
        cout << "Add a topping: " << endl;
        Topping Topping;
        cin >> Topping;
        fout << Topping;
        cout << "Continue? (y/n) ";
        cin >> userInput;
    } while(userInput == 'y');
            }
            if (c == '3') {
            }
            if (c == '4') {
            }
            if (c == '5') {
            }
            if (c == '6') {
            }
    }


}
