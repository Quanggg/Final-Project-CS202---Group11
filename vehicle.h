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
    const int CAR_LOCATION_Y = 25,
              TRUCK_LOCATION_Y = 13,
              CAR_LENGTH = 8,
              TRUCK_LENGTH = 8;

    int DIVIDE_CONSTANT = 1000000;

    void CarMove(const int &ElapsedTime);
    void TruckMove(const int &ElapsedTime);

public:
    int _Level = 1;
    std::deque<Vehicle *> _CarLane, _TruckLane;

    VehicleControl();

    void CreateObj();
    void Move(const int &ElapsedTime);
    void SetLevel(const int &x);

    void AddCar();
    void AddTruck();
};