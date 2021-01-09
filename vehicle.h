#pragma once
#include "all.h"

class Car : public Object
{
public:
    Car(int x, int y);
    ~Car();
};

class Truck : public Object
{
public:
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

    void CarMove(const int &ElapsedTime);
    void TruckMove(const int &ElapsedTime);

public:
    std::deque<Object *> _CarLane, _TruckLane;

    Vehicle(const int &level, const bool &call_CreateObj = true);
    ~Vehicle();

    void CreateObj();
    void Move(const int &ElapsedTime);

    void AddRandomCar();
    void AddRandomTruck();

    void AddCar(Object *obj);
    void AddTruck(Object *obj);

    void SaveVehicle(std::ofstream &f);
};