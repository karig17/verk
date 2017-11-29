#include "Topping.h"

Topping::Topping() {
    name[0] = '\0';
    price = 0.0;
}

ostream& operator << (ostream& out, const Topping& topping) {
    out << '\t' << setw(topping.MAX_STR_LENGHT) << topping.name << " " << topping.price << endl;
    return out;
}
