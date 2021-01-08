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

class Animal
{
private:
    const int BIRD_LOCATION_Y = 7,
        DINOSAUR_LOCATION_Y = 18,
        BIRD_LENGTH = 5,
        DINOSAUR_LENGTH = 17;

    // change (x, y) of Bird in _BirdLane
    void BirdMove(const int& ElapsedTime);
    // change (x, y) of Dinosaur in _DinosaurLane
    void DinosaurMove(const int& ElapsedTime);
public:
    std::deque<Object*> _BirdLane, _DinosaurLane;
    void CreateObj();

};

