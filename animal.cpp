#pragma once
#include "animal.h"

#define WIDTH Console::MAP_WIDTH
#define HEIGHT Console::MAP_HEIGHT
#define MAP Console::MAP_LOCATION

//
Bird::Bird(int x, int y)
{
    _Direction = 1;
    _Pos = {x, y};
    _Pos.SetMax(MAP._x + WIDTH - 1, MAP._y + HEIGHT - 1);
    _Pos.SetMin(MAP._x - 4, MAP._y + 1);
    _STRING.assign(4, "");
    _STRING[0] = " ,_,";
    _STRING[1] = "(.,.)";
    _STRING[2] = "(___)";
    _STRING[3] = " \" \"";
}
Bird::~Bird() {}

//
Dinosaur::Dinosaur(int x, int y)
{
    _Direction = -1;
    _Pos = {x, y};
    _Pos.SetMax(MAP._x + WIDTH - 1, MAP._y + HEIGHT - 1);
    _Pos.SetMin(MAP._x - 17, MAP._y + 1);

    _STRING.assign(6, "");
    _STRING[0] = " __";
    _STRING[1] = "(_ \\";
    _STRING[2] = "  \\ \\_.----._";
    _STRING[3] = "   \\         \\";
    _STRING[4] = "    |  ) |  ) \\_";
    _STRING[5] = "    |_|--|_|'-._\\";
}
Dinosaur::~Dinosaur() {}

void Animal::BirdMove(const int& ElapsedTime)
{
    for (auto i : _BirdLane)
    {
        if (i->_Pos._x == i->_Pos.max_x)
        {
            _BirdLane.pop_back();
        }
    }
}
void Animal::DinosaurMove(const int& ElapsedTime)
{
    int k = 0;
    for (auto i : _DinosaurLane)
    {
        if (i->_Pos._x == i->_Pos.min_x)
        {
            _DinosaurLane.pop_front();
        }
    }
}




