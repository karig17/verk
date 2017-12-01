#include "Order.h"

Order::Order()
{
    Topping topping;
    Extras extra;
}

Order::~Order()
{
    //dtor
}

void Order::pizzaOrders() {
    Topping topping;
    char cont;
    int i = 0;

    cout << endl << "Choose toppings: " << endl;

    int lines = topping.getLines();
    Topping* toppingMaster = topping.readFile();

    for(int j = 0; j < lines; j++) {
        cout << (j + 1) << toppingMaster[j];
    }

    do {
        int userInput[pizzas[0].MAX_TOPPINGS_PIZZA];
        int counter = 0;
        cout << "Select toppings, press 0 to stop." << endl;

        while(counter < pizzas[0].MAX_TOPPINGS_PIZZA) {
            cin >> userInput[counter];
            if(userInput[counter] == 0) {
                break;
            }
            counter++;
        }

        for(int k = 0; k < counter; k++) {
            pizzas[i].addTopping(toppingMaster[userInput[k] - 1]);
        }

        cout <<"add another pizza to the order? (y/n):";
        cin >>cont;
        if(cont == 'y') {
            i++;
        }
    } while(cont == 'y');
        cout <<"Your pizzas: "<< endl;
        for(int j = 0; j <= i; j++) {
        cout << pizzas[j];
    }

}

void Order::setDelMethod() {
    char delivery;
    cout <<"pick up or delivery?(p/d): ";
    cin >>delivery;
    _delMethod= delivery;
}

void Order::setAddress() {
    if(_delMethod == 'd') {
        string address;
        cout <<"address: ";
        cin >>ws;
        getline(cin, address);
        for(unsigned int i = 0; i < address.size(); i++) {
            if(i == MAX_ADDRESS_LENGTH -1) {
                break;
            }
            _address[i] = address.at(i);
        }
        _address[address.size()] = '\0';
        _address[MAX_ADDRESS_LENGTH -1] = '\0';
    }
}

void Order::setComments() {
    char svar;
    string comment;
    cout <<"any comments?(y/n): ";
    cin >>svar;
    if(svar == 'y') {
        cout <<"comments :";
        cin >>ws;
        getline(cin, comment);
        for(unsigned int i = 0; i < comment.size(); i++) {
            if(i == MAX_COMMENT_LENGTH -1)
                break;
            _comments[i] = comment.at(i);
        }
        _comments[comment.size()] = '\0';
        _comments[MAX_COMMENT_LENGTH - 1] = '\0';
    }
}
void Order::setExtras() {

}
void Order::setPaymentStatus() {
    char svar;
    cout <<"set payment status (\'p\' for paid or \'n\' for pay on delivery): ";
    cin >>svar;
    if( svar == 'p') {
        _paymentStatus = true;
    }
    else {
        _paymentStatus = false;
    }
}
void Order::setOrderStatus() {
    char svar;
    do{
        cout <<"Set order status (\'p\' for preperation or \'r\' for ready): ";
        cin >>svar;
    }while(svar != 'p' && svar != 'r');
}
