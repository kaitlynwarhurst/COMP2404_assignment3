#include "Pierres.h"

Pierres::Pierres(){

}

void Pierres::addDriver(const string& name, const Location& location){
    Driver* d = new Driver(name, location);
    drivers.push_back(d);
}

void Pierres::addFranchise(const string& name, const Location& location){
    Franchise* f = new Franchise(name, location);
    franchises.push_back(f);
}

void Pierres::takeOrder(const string& customerName, int menuItem, const Location& location){
    if(franchises.empty()){
        cout<< "Error: Franchises empty"<<endl;
        return;
    }
    Order o = Order(customerName, menuItem, location);
    Order* oPtr;
    *oPtr = o;
    int minDistance =(franchises[0]-> getLocation()).getDistance(location);
    int i =0;
    int closest = i;
    for(auto& f : franchises){
        int tempDist= (f->getLocation()).getDistance(location);
        if(tempDist<minDistance){
            minDistance= tempDist;
            closest = i;
        }
        ++i;
    }
    franchises[closest]->addOrder(oPtr);
}

void Pierres::driverPickup(const string& franshiseID, int numOrders){
    if(drivers.empty()){
        cout<< "Error: No Drivers"<<endl;
        return;
    }
    bool foundFranchise = false;
    Location l;
    int numFranchiseOrders=0;
    Franchise* franchiseBranch;
    for(auto& f: franchises){
        if(f->equals(franshiseID)){
            foundFranchise = true;
            l = f->getLocation();
            numFranchiseOrders = f->getNumOrders();
            franchiseBranch = f;
            break;
        }
    }
    if(foundFranchise== false){
        cout<< "Error: Franchise does not exist"<<endl;
        return;
    }
   // cout<<"Franchise Found!"<<endl;
    int minDistance =l.getDistance(drivers[0]->getLocation());
    //cout<< "Min distance calculatedS"<< endl;
    int i =0;
    int closest = i;
    for(auto& d : drivers){
        //cout<< "driver: "<<endl;
        //d->print();
        int tempDist= l.getDistance(d->getLocation());
        if(tempDist<minDistance && d->isFree() ){
            minDistance= tempDist;
            closest =i;
        }
        ++i;
    }
    //cout<<"loop successfully exited"<<endl;
    //cout<< "X: "<< l.getX()<< "Y: " << l.getY()<<endl;
    drivers[closest]->setLocation(l.getX(), l.getY());
    //cout<< "location set!"<< endl;
    if(numOrders>= numFranchiseOrders ){
        for(int k=0;k<numFranchiseOrders;++k){
            drivers[k]->addOrder(franchiseBranch->getNextOrder());
        }
    }
    else{
        for(int k=0;k<numOrders;++k){
            drivers[k]->addOrder(franchiseBranch->getNextOrder());
        }
    }
}

void Pierres::driverDeliver(const string& driverID, int numOrders){
    if(drivers.empty()){
        cout<<"Error: No drivers"<<endl;
        return;
    }
    bool foundDriver = false;
    Driver* curDriver;
    for( auto& d : drivers){
        if(d->equals(driverID)){
            foundDriver = true;
            curDriver = d;
            break;
        }
    }
    if(!foundDriver){
        cout<< "Error: Driver not found"<<endl;
    }
    if(numOrders>= curDriver->getNumOrders()){
        for(int i =0; i< curDriver->getNumOrders(); ++i){
            Order* o = curDriver->getNextOrder();
            curDriver->setLocation(o->locationGetter().getX(), o->locationGetter().getY());
            cout<< "Delivering: "<<endl;
            o->print();
        }
    }
    else{
        for(int i =0; i< numOrders; ++i){
            Order* o = curDriver->getNextOrder();
            curDriver->setLocation(o->locationGetter().getX(), o->locationGetter().getY());
            cout<< "Delivering: "<<endl;
            o->print();
        }
    }
}

void Pierres::printFranchises() const{
    if(franchises.empty()) return;
    for(auto& f: franchises){
        f->print();
    }
}

void Pierres::printDrivers() const{
    if(drivers.empty()) return;
    for(auto& d: drivers){
        d->print();
    }
}