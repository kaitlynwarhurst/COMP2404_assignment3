#include "Driver.h"

int Driver::nextID =1;

Driver::Driver(const string& name, const Location& location):Entity(code,nextID++,name,location){

}

bool Driver::isFree() const{
    return orders.empty();
}

void Driver::print() const{
    cout<<"Driver ";
    Entity::print();
}