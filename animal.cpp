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
            delete i;
            _BirdLane.pop_back();
        }
        else
            i->Move(ElapsedTime);
    }
}

Animal::Animal(const int& level, const bool& call_CreateObj)
{
    if (call_CreateObj)
        Animal::CreateObj();
    Object::ChangeLevel(level);
}
Animal::~Animal()
{
    for (auto i : _BirdLane)
        delete i;

    for (auto i : _DinosaurLane)
        delete i;
}

void Animal::DinosaurMove(const int& ElapsedTime)
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
            i->Move(ElapsedTime);
    }
}

void Animal::CreateObj()
{
    srand(time(NULL));
    Object* v;
    int _RandomDistance, NEW_LOCATION;
    //create 4 Bird obj with random distance
    //Bird1 Bird2 Bird3 Bird4
    for (int i = 0; i < 3; i++)
    {
        if (!i)
            v = new Bird(MAP._x + 2, MAP._y + BIRD_LOCATION_Y);
        else
        {
            _RandomDistance = rand() % 25 + 1;
            NEW_LOCATION = _BirdLane[i - 1]->_Pos._x + BIRD_LENGTH + _RandomDistance;

            v = new Bird(NEW_LOCATION, MAP._y + BIRD_LOCATION_Y);
        }
        _BirdLane.push_back(v);
    }

    //create 4 Dinosaur obj with random distance
    //Dinosaur4 Dinosaur3 Dinosaur2 Dinosaur1
    for (int i = 0; i < 3; i++)
    {
        if (!i)
            v = new Dinosaur(MAP._x + WIDTH - 1, MAP._y + DINOSAUR_LOCATION_Y);
        else
        {
            _RandomDistance = rand() % 25 + 1;
            NEW_LOCATION = _DinosaurLane.front()->_Pos._x - DINOSAUR_LENGTH - _RandomDistance;

            v = new Dinosaur(NEW_LOCATION, MAP._y + DINOSAUR_LOCATION_Y);
        }
        _DinosaurLane.push_front(v);
    }
}

void Animal::Move(const int& ElapsedTime)
{
    Animal::BirdMove(ElapsedTime);
    Animal::AddRandomBird();

    Animal::DinosaurMove(ElapsedTime);
    Animal::AddRandomDinosaur();
}

void Animal::AddRandomBird()
{
    srand(time(NULL));
    if (_BirdLane.front()->_Pos._x > rand() % 35 + BIRD_LENGTH + 1)
        _BirdLane.push_front(new Bird(MAP._x - 4, MAP._y + BIRD_LOCATION_Y));
}
void Animal::AddRandomDinosaur()
{
    srand(time(NULL));
    if (_DinosaurLane.back()->_Pos._x < MAP._x + WIDTH - rand() % 35 - DINOSAUR_LENGTH - 1)
        _DinosaurLane.push_back(new Dinosaur(MAP._x + WIDTH - 1, MAP._y + DINOSAUR_LOCATION_Y));
}

void Animal::AddBird(Object* obj)
{
    _BirdLane.push_back(obj);
}
void Animal::AddDinosaur(Object* obj)
{
    _DinosaurLane.push_back(obj);
}

void Animal::SaveAnimal(std::ofstream& f)
{
    f << _BirdLane.size() << '\n';
    for (auto i : _BirdLane)
        f << i->_Pos._x << " " << i->_Pos._y << '\n';
    f << _DinosaurLane.size() << '\n';
    for (auto i : _DinosaurLane)
        f << i->_Pos._x << " " << i->_Pos._y << '\n';
}



