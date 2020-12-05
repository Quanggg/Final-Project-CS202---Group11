#pragma once
#include "all.h"

const Coordinate MAP_LOCATION(5, 2);

class Vehicle
{
public:
    int _Direction;
    float _Distance, _DistanceSum;

    Coordinate _Pos;
    std::vector<std::string> _STRING;
    std::deque<Vehicle *> _Lane;

    Vehicle();
    virtual ~Vehicle();
};

class Car : public Vehicle
{
public:
    Car();
    Car(int x, int y);
    ~Car();
};

class Truck : public Vehicle
{
public:
    Truck();
    Truck(int x, int y);
    ~Truck();
};

class VehicleControl
{
private:
    const int CAR_LOCATION_Y = 26,
              TRUCK_LOCATION_Y = 13,
              CAR_LENGTH = 13,
              TRUCK_LENGTH = 19;

    int DIVIDE_CONSTANT = 1000000;

    void CarMove(const int &ElapsedTime);
    void TruckMove(const int &ElapsedTime);

public:
    std::deque<Vehicle *> _CarLane, _TruckLane;

    VehicleControl(const int &level);
    ~VehicleControl();

    void CreateObj();
    void Move(const int &ElapsedTime);

    void AddCar();
    void AddTruck();
};