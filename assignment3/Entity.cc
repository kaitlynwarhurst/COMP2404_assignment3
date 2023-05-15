#include "Entity.h"

void Entity::setLocation(int x, int y){
    entityLocation.setLocation(x,y);
}

Entity::Entity(char c, int i, string franchiseName,const Location& location){
    id = c + std::to_string(i);
    name = franchiseName; 
    entityLocation = Location(location.x,location.y);
    orders = Queue();
}

int Entity::getNumOrders() const{
    return orders.size();
}

Order* Entity::getNextOrder(){
    return orders.popFirst();
}

void Entity::addOrder(Order* order){
    orders.addLast(order);
}

void Entity::print() const{
    cout<< "ID: " << id << " Name: " << name << " Location: ";
    entityLocation.print();
    cout<< " Number of Orders: "<< orders.size()<<endl;
}

bool Entity::equals(const string& entityID) const {
    return entityID== id;
}

Location Entity::getLocation() const{
    return entityLocation;
}
