#include "Topping.h"

Topping::Topping()
{
    //ctor
}

ostream& operator << (ostream& out, const Topping& topping) {
    out << '\t' << setw(topping.MAX_STR_LENGTH) << topping.name << " " << topping.price << endl;
    return out;
}
