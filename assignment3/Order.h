#ifndef ORDER_H
#define ORDER_H

#include "Location.h"
//#include "Franchise.h"

using namespace std;

class Order{
    private:
        string name;
        int menuItem;
        Location deliveryLocation;
    public:
        Order(const string& orderName, const int& itemNum, const Location& location);
        Location locationGetter() const;
        void print() const;

};



#endif