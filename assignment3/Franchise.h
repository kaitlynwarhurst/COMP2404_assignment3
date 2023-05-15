#ifndef FRANCHISE_H
#define FRANCHISE_H

#include "Entity.h"
#include "defs.h"


class Franchise: public Entity{
    private:
        static const char code = 'F';
        static int nextID;
        static const string menu[MENU_ITEMS];
    public: 
        Franchise(const string& name = "defaultFranchise", const Location& location = Location());
        void print() const;
        static void printMenu();
        static string getMenu(int index);
};

#endif