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

class Vehicle
{
private:
    const int CAR_LOCATION_Y = 26,
              TRUCK_LOCATION_Y = 13,
              CAR_LENGTH = 13,
              TRUCK_LENGTH = 19;

    // change (x, y) of Car in _CarLane
    void CarMove(const int &ElapsedTime);
    // change (x, y) of Truck in _TruckLane
    void TruckMove(const int &ElapsedTime);

public:
    std::deque<Object *> _CarLane, _TruckLane;

    // create object base on level
    // call_CreateObj = false when load game from file, no need to create obj
    Vehicle(const int &level, const bool &call_CreateObj = true);
    ~Vehicle();

    // create random 3 object
    void CreateObj();
    void Move(const int &ElapsedTime);

    // add object with random distance
    void AddRandomCar();
    void AddRandomTruck();
};