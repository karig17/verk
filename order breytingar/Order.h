#ifndef ORDER_H
#define ORDER_H

#include "Extras.h"
#include "Pizza.h"

class Order
{
    public:
        Order();
        virtual ~Order();
        void pizzaOrders();
        void setDelMethod();
        void setAddress();
        void setExtras();
        void setComments();
        void setPaymentStatus();
        void setOrderStatus();


    private:
        static const int MAX_PIZZAS_ORDER = 10;
        static const int MAX_EXTRAS_ORDER = 10;
        static const int MAX_ADDRESS_LENGTH = 30;
        static const int MAX_COMMENT_LENGTH = 50;

        Pizza pizzas[MAX_PIZZAS_ORDER];
        char _address[MAX_ADDRESS_LENGTH];
        char _delMethod;
        Extras extras[MAX_EXTRAS_ORDER];
        int _location;
        int _totalPirce;
        bool _paymentStatus;
        char _comments[MAX_COMMENT_LENGTH];
        char _orderStatus;

};

#endif // ORDER_H
