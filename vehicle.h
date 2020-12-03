#pragma once
#include <deque>
#include <vector>
#include <string>
#include "coordinate.h"
#include <time.h>
#include <random>
// xem coordinate.h

const int MAP_WIDTH = 92,
          MAP_HEIGHT = 36;
const Coordinate MAP_LOCATION = {5, 2};
srand(time(NULL));
class Vehicle
{
private:
    const int LANE_LOCATION = 10;
    int DIVIDE_CONSTANT = 1000000;

public:
    float _Distance, _DistanceSum;
    int _Direction, _Level = 1;
    Coordinate _Pos;
    Vehicle();
    Vehicle(int x) {}
    std::vector<std::string> _STRING;
    std::deque<Vehicle *> _Lane;
    void Move(const int &ElapsedTime)
    {
        for (auto i : _Lane)
        {
            if (i->_Pos._x == i->_Pos.max_x)
            {
                _Lane.pop_back();
            }
            else
            {
                i->_DistanceSum = 1.0 * ElapsedTime / DIVIDE_CONSTANT;
                i->_Distance += i->_DistanceSum;
                i->_Pos.SetX(i->_Direction * floor(i->_Distance));
                if (i->_Distance > 1)
                    i->_Distance = 0;
            }
        }
    }
    void CreateObj();
    void SetLevel(const int &x)
    {
        _Level = x;
        DIVIDE_CONSTANT = 10000000 - x * 500000;
    }
    virtual ~Vehicle() {}
};

class car : public Vehicle
{
public:
    car() {}
    car(int x, int y);
    ~car(){};
};
Vehicle::Vehicle()
{
    CreateObj();
}
void Vehicle::CreateObj()
{
    int n = rand() % 3 + 4;
    Vehicle *v;
    for (int i = 0; i < n; i++)
    {
        if (!i)
            v = new car(MAP_LOCATION._x + 2, MAP_LOCATION._y + 25);
        else
            v = new car(v[i - 1]._Pos._x + 5 + rand() % 5 + 1, MAP_LOCATION._y + 25);
        _Lane.push_back(v);
    }
}
car::car(int x, int y) : Vehicle(x)
{
    _Direction = 1;
    _Pos = {x, y};
    _Pos.SetMax(MAP_LOCATION._x + MAP_WIDTH - 1, MAP_LOCATION._y + MAP_HEIGHT - 1);
    _Pos.SetMin(MAP_LOCATION._x + 1, MAP_LOCATION._y + 1);
    _STRING.assign(5, "");
    _STRING[0] = " ------";
    _STRING[1] = "| car  |";
    _STRING[2] = "|      |";
    _STRING[3] = " ------";
    _STRING[4] = "O o  o O";
}