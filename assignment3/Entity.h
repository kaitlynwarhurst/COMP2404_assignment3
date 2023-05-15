#ifndef ENTITY_H
#define ENTITY_H

#include "Location.h"
#include "Queue.h"

using namespace std;

class Entity{
    protected:
        string id;
        string name;
        Location entityLocation;
        Queue orders;
    
    public:
        Entity(char c, int i, string franchiseName,const Location& location);
        void setLocation(int x, int y);
        int getNumOrders() const;
        Order* getNextOrder();
        void addOrder(Order* order);
        void print() const;
        bool equals(const string& entityID) const;
        Location getLocation() const;

};

#endif