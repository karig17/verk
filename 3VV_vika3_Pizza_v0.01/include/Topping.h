#ifndef TOPPING_H
#define TOPPING_H

#include <iostream>
#include <iomanip>
using namespace std;


class Topping
{
    public:
        Topping();

        friend ostream& operator << (ostream& out, const Topping& topping);

    private:
        static const int MAX_STR_LENGHT = 24;

        char name[MAX_STR_LENGHT];
        double price;
        //int pricingCategory;


};

#endif // TOPPING_H
