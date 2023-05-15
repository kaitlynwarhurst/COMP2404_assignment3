#include "Franchise.h"

int Franchise::nextID =1;
const string Franchise::menu[MENU_ITEMS] =  {"1. Large Poutine", "2. Medium Poutine", "3. Small Poutine"};

Franchise::Franchise(const string& name, const Location& location):Entity(code,nextID++,name,location){
}

void Franchise::print() const{
    cout<< "Franchise: ";
    Entity::print();
}

void Franchise::printMenu(){
    cout<< "Menu:"<< endl;
    for(int i = 0; i< MENU_ITEMS;++i){
        cout<<menu[i]<<endl;
    }
}

string Franchise::getMenu(int index){
    if(index<0 || index>= MENU_ITEMS){
        return "unknown menu item";
    }
    return menu[index];
}

