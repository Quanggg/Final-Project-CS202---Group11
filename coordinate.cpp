#pragma once
#include "coordinate.h"

//
Coordinate::Coordinate() : _x(0), min_x(0), max_x(0), _y(0), min_y(0), max_y(0){};
Coordinate::Coordinate(const int &a, const int &b) : _x(a), min_x(0), max_x(0), _y(b), min_y(0), max_y(0){};
Coordinate::Coordinate(const Coordinate &pos) : _x(pos._x), min_x(pos.min_x), max_x(pos.max_x), _y(pos._y), min_y(pos.min_y), max_y(pos.max_x){};
Coordinate::~Coordinate() {}

//
void Coordinate::SetX(const int &distance)
{
    if (_x + distance >= min_x && _x + distance <= max_x)
        _x += distance;
}
void Coordinate::SetY(const int &distance)
{
    if (_y + distance >= min_y && _y + distance <= max_y)
        _y += distance;
}

//
void Coordinate::SetMax(const int &a, const int &b)
{
    max_x = a, max_y = b;
}
void Coordinate::SetMin(const int &a, const int &b)
{
    min_x = a, min_y = b;
}
