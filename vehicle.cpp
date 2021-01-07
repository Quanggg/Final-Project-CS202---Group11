#pragma once
#include "vehicle.h"

#define WIDTH Console::MAP_WIDTH
#define HEIGHT Console::MAP_HEIGHT
#define MAP Console::MAP_LOCATION

//
Car::Car(int x, int y)
{
    _Direction = 1;
    _Pos = {x, y};
    _Pos.SetMax(MAP._x + WIDTH - 1, MAP._y + HEIGHT - 1);
    _Pos.SetMin(MAP._x - 4, MAP._y + 1);

    _STRING.assign(4, "");
    _STRING[0] = "  ______";
    _STRING[1] = " /|_||_\\`.__";
    _STRING[2] = "(   _    _ _\\";
    _STRING[3] = "=`-(_)--(_)-'";
}
Car::~Car() {}

//
Truck::Truck(int x, int y)
{
    _Direction = -1;
    _Pos = {x, y};
    _Pos.SetMax(MAP._x + WIDTH - 1, MAP._y + HEIGHT - 1);
    _Pos.SetMin(MAP._x - 18, MAP._y + 1);

    _STRING.assign(5, "");
    _STRING[0] = "        __________";
    _STRING[1] = "  ___  |          |";
    _STRING[2] = " /_| | |          |";
    _STRING[3] = "|    |_|__________|";
    _STRING[4] = "\"-O----O-O`    O`O`";
}
Truck::~Truck() {}

//
void Vehicle::CarMove(const int &ElapsedTime)
{
    for (auto i : _CarLane)
    {
        if (i->_Pos._x == i->_Pos.max_x)
        {
            delete i;
            _CarLane.pop_back();
        }
        else
            i->Move(ElapsedTime);
    }
}
void Vehicle::TruckMove(const int &ElapsedTime)
{
    int k = 0;
    for (auto i : _TruckLane)
    {
        if (i->_Pos._x == i->_Pos.min_x)
        {
            delete i;
            _TruckLane.pop_front();
        }
        else
            i->Move(ElapsedTime);
    }
}

//
Vehicle::Vehicle(const int &level, const bool &call_CreateObj)
{
    if (call_CreateObj)
        Vehicle::CreateObj();
    Object::ChangeLevel(level);
}
Vehicle::~Vehicle()
{
    for (auto i : _CarLane)
        delete i;
    for (auto i : _TruckLane)
        delete i;
}
//
void Vehicle::CreateObj()
{
    srand(time(NULL));
    Object *v;
    int _RandomDistance, NEW_LOCATION;
    //create 4 car obj with random distance
    //car1 car2 car3 car4
    for (int i = 0; i < 3; i++)
    {
        if (!i)
            v = new Car(MAP._x + 2, MAP._y + CAR_LOCATION_Y);
        else
        {
            _RandomDistance = rand() % 25 + 1;
            NEW_LOCATION = _CarLane[i - 1]->_Pos._x + CAR_LENGTH + _RandomDistance;

            v = new Car(NEW_LOCATION, MAP._y + CAR_LOCATION_Y);
        }
        _CarLane.push_back(v);
    }

    //create 4 truck obj with random distance
    //truck4 truck3 truck2 truck1
    for (int i = 0; i < 3; i++)
    {
        if (!i)
            v = new Truck(MAP._x + Console::MAP_WIDTH - 1, MAP._y + TRUCK_LOCATION_Y);
        else
        {
            _RandomDistance = rand() % 25 + 1;
            NEW_LOCATION = _TruckLane.front()->_Pos._x - TRUCK_LENGTH - _RandomDistance;

            v = new Truck(NEW_LOCATION, MAP._y + TRUCK_LOCATION_Y);
        }
        _TruckLane.push_front(v);
    }
}
void Vehicle::Move(const int &ElapsedTime)
{
    Vehicle::CarMove(ElapsedTime);
    Vehicle::AddRandomCar();

    Vehicle::TruckMove(ElapsedTime);
    Vehicle::AddRandomTruck();
}

//
void Vehicle::AddRandomCar()
{
    srand(time(NULL));
    if (_CarLane.front()->_Pos._x > rand() % 35 + CAR_LENGTH + 1)
        _CarLane.push_front(new Car(MAP._x - 4, MAP._y + CAR_LOCATION_Y));
}
void Vehicle::AddRandomTruck()
{
    srand(time(NULL));
    if (_TruckLane.back()->_Pos._x < MAP._x + WIDTH - rand() % 35 - TRUCK_LENGTH - 1)
        _TruckLane.push_back(new Truck(MAP._x + WIDTH - 1, MAP._y + TRUCK_LOCATION_Y));
}

//
void Vehicle::AddCar(Object *obj)
{
    _CarLane.push_back(obj);
}
void Vehicle::AddTruck(Object *obj)
{
    _TruckLane.push_back(obj);
}

//
void Vehicle::SaveVehicle(std::ofstream &f)
{
    f << _CarLane.size() << '\n';
    for (auto i : _CarLane)
        f << i->_Pos._x << " " << i->_Pos._y << '\n';
    f << _TruckLane.size() << '\n';
    for (auto i : _TruckLane)
        f << i->_Pos._x << " " << i->_Pos._y << '\n';
}