#pragma once
#include "all.h"

class Car : public Object
{
public:
    // (x, y) is the first location of object when created
    Car(int x, int y);
    ~Car();
};

class Truck : public Object
{
public:
    // (x, y) is the first location of object when created
    Truck(int x, int y);
    ~Truck();
};