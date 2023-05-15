#include "Order.h"
#include "Franchise.h"

Order::Order(const string& orderName, const int& itemNum, const Location& location){
    name = orderName;
    menuItem = itemNum;
    deliveryLocation = location;
}

Location Order::locationGetter() const{
    return deliveryLocation;
}

void Order::print() const{
    string menuValue = Franchise::getMenu(menuItem);
    cout<< "menuItem Number: " << menuValue << endl;
}

