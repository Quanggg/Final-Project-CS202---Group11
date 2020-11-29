#pragma once

class Coordinate
{
public:
    int _x, _y;
    int min_x, min_y;
    int max_x, max_y;
    Coordinate() : _x(0), min_x(0), max_x(0), _y(0), min_y(0), max_y(0){};
    Coordinate(const int &a, const int &b) : _x(a), min_x(0), max_x(0), _y(b), min_y(0), max_y(0){};
    void SetX(const int &distance)
    {
        if (_x + distance >= min_x && _x + distance <= max_x)
            _x += distance;
    }
    void SetY(const int &distance)
    {
        if (_y + distance >= min_y && _y + distance <= max_y)
            _y += distance;
    }
    void SetMax(const int &a, const int &b)
    {
        max_x = a, max_y = b;
    }
    void SetMin(const int &a, const int &b)
    {
        min_x = a, min_y = b;
    }
    Coordinate(const Coordinate &pos) : _x(pos._x), min_x(pos.min_x), max_x(pos.max_x), _y(pos._y), min_y(pos.min_y), max_y(pos.max_x){};
    ~Coordinate(){};
};