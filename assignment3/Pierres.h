#ifndef PIERRES_H
#define PIERRES_H

#include "Driver.h"
#include "Franchise.h"
#include "Entity.h"
#include "Order.h"
#include <vector>

using namespace std;

class Pierres{
    private:
        vector<Driver*> drivers;
        vector<Franchise*> franchises;
    public:
        Pierres();
        void addDriver(const string& name, const Location& location);
        void addFranchise(const string& name, const Location& location);
        void takeOrder( const string& customerName, int menuItem, const Location& location);
        void driverPickup(const string& franchiseID, int numOrders);
        void driverDeliver(const string& driverID, int numOrders);
        void printFranchises() const;
        void printDrivers() const;

};

#endif