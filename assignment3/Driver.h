#ifndef DRIVER_H
#define DRIVER_H

#include "Entity.h"

class Driver: public Entity{
    private:
        static const char code = 'D';
        static int nextID;
    public:
        Driver(const string& name = "default", const Location& location = Location());
        bool isFree() const;
        void print() const;
};

#endif