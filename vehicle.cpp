#pragma once
#include "vehicle.h"

#define WIDTH Console::MAP_WIDTH
#define HEIGHT Console::MAP_HEIGHT
#define MAP Console::MAP_LOCATION

//
Car::Car(int x, int y)
{
    _Direction = 1;
    _Pos = { x, y };
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
    _Pos = { x, y };
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