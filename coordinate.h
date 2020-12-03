#pragma once

class Coordinate
{
public:
    int _x, _y;
    int min_x, min_y;
    int max_x, max_y;

    Coordinate();
    Coordinate(const int &a, const int &b);
    Coordinate(const Coordinate &pos);
    ~Coordinate();

    void SetX(const int &distance);
    void SetY(const int &distance);

    void SetMax(const int &a, const int &b);
    void SetMin(const int &a, const int &b);
};