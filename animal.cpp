#pragma once
#include "animal.h"

//
Animal::Animal() {}
Animal::~Animal() {}

//
Bird::Bird() {}
Bird::Bird(int x, int y) : Animal()
{
    _Direction = 1;
    _Pos = {x, y};
    _Pos.SetMax(MAP_LOCATION._x + Console::MAP_WIDTH - 1, MAP_LOCATION._y + Console::MAP_HEIGHT - 1);
    _Pos.SetMin(MAP_LOCATION._x - 4, MAP_LOCATION._y + 1);
    _STRING.assign(4, "");
    _STRING[0] = " ,_,";
    _STRING[1] = "(.,.)";
    _STRING[2] = "(___)";
    _STRING[3] = " \" \"";
}
Bird::~Bird() {}

//
Dinosaur::Dinosaur() {}
Dinosaur::Dinosaur(int x, int y) : Animal()
{
    _Direction = -1;
    _Pos = {x, y};
    _Pos.SetMax(MAP_LOCATION._x + Console::MAP_WIDTH - 1, MAP_LOCATION._y + Console::MAP_HEIGHT - 1);
    _Pos.SetMin(MAP_LOCATION._x - 17, MAP_LOCATION._y + 1);
    _STRING.assign(6, "");
    _STRING[0] = " __";
    _STRING[1] = "(_ \\";
    _STRING[2] = "  \\ \\_.----._";
    _STRING[3] = "   \\         \\";
    _STRING[4] = "    |  ) |  ) \\_";
    _STRING[5] = "    |_|--|_|'-._\\";
}
Dinosaur::~Dinosaur() {}

//
void AnimalControl::BirdMove(const int &ElapsedTime)
{
    for (auto i : _BirdLane)
    {
        if (i->_Pos._x == i->_Pos.max_x)
        {
            delete i;
            _BirdLane.pop_back();
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
void AnimalControl::DinosaurMove(const int &ElapsedTime)
{
    int k = 0;
    for (auto i : _DinosaurLane)
    {
        if (i->_Pos._x == i->_Pos.min_x)
        {
            delete i;
            _DinosaurLane.pop_front();
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

//
AnimalControl::AnimalControl(const int &level, const bool &b)
{
    if (b)
        AnimalControl::CreateObj();
    DIVIDE_CONSTANT -= 70000 * sqrt(level);
}
AnimalControl::~AnimalControl()
{
    for (auto i : _BirdLane)
        delete i;
    for (auto i : _DinosaurLane)
        delete i;
}

//
void AnimalControl::CreateObj()
{
    srand(time(NULL));
    Animal *v;
    int _RandomDistance, NEW_LOCATION;
    //create 4 Bird obj with random distance
    //Bird1 Bird2 Bird3 Bird4
    for (int i = 0; i < 2; i++)
    {
        if (!i)
            v = new Bird(MAP_LOCATION._x + 2, MAP_LOCATION._y + BIRD_LOCATION_Y);
        else
        {
            _RandomDistance = rand() % 30 + 1;
            NEW_LOCATION = _BirdLane[i - 1]->_Pos._x + BIRD_LENGTH + _RandomDistance;

            v = new Bird(NEW_LOCATION, MAP_LOCATION._y + BIRD_LOCATION_Y);
        }
        _BirdLane.push_back(v);
    }

    //create 4 Dinosaur obj with random distance
    //Dinosaur4 Dinosaur3 Dinosaur2 Dinosaur1
    for (int i = 0; i < 2; i++)
    {
        if (!i)
            v = new Dinosaur(MAP_LOCATION._x + Console::MAP_WIDTH - 1, MAP_LOCATION._y + DINOSAUR_LOCATION_Y);
        else
        {
            _RandomDistance = rand() % 30 + 1;
            NEW_LOCATION = _DinosaurLane.front()->_Pos._x - DINOSAUR_LENGTH - _RandomDistance;

            v = new Dinosaur(NEW_LOCATION, MAP_LOCATION._y + DINOSAUR_LOCATION_Y);
        }
        _DinosaurLane.push_front(v);
    }
}
void AnimalControl::Move(const int &ElapsedTime)
{
    AnimalControl::BirdMove(ElapsedTime);
    AnimalControl::AddBird();

    AnimalControl::DinosaurMove(ElapsedTime);
    AnimalControl::AddDinosaur();
}

//
void AnimalControl::AddBird()
{
    srand(time(NULL));
    if (_BirdLane.front()->_Pos._x > rand() % 35 + BIRD_LENGTH + 1)
        _BirdLane.push_front(new Bird(MAP_LOCATION._x - 4, MAP_LOCATION._y + BIRD_LOCATION_Y));
}
void AnimalControl::AddDinosaur()
{
    srand(time(NULL));
    if (_DinosaurLane.back()->_Pos._x < MAP_LOCATION._x + Console::MAP_WIDTH - rand() % 35 - DINOSAUR_LENGTH - 1)
        _DinosaurLane.push_back(new Dinosaur(MAP_LOCATION._x + Console::MAP_WIDTH - 1, MAP_LOCATION._y + DINOSAUR_LOCATION_Y));
}