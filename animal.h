#pragma once
#include "all.h"

//const Coordinate MAP_LOCATION(5, 2);

class Bird : public Object
{
public:
    // (x, y) is the first location of object when created
    Bird(int x, int y);
    ~Bird();
};

class Dinosaur : public Object
{
public:
    // (x, y) is the first location of object when created
    Dinosaur(int x, int y);
    ~Dinosaur();
};

