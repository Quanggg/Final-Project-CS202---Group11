#pragma once
#include "object.h"

Object::Object() {}
Object::~Object() {}

int Object::DIVIDE_CONSTANT = 1000000;

void Object::Move(const int &ElapsedTime)
{
    _DistanceSum = 1.0 * ElapsedTime / DIVIDE_CONSTANT;
    _Distance += _DistanceSum;
    _Pos.SetX(_Direction * floor(_Distance));
    if (_Distance > 1)
        _Distance = 0;
}

void Object::ChangeLevel(const int &level)
{
    DIVIDE_CONSTANT = 1000000 - 100000 * sqrt(level);
}