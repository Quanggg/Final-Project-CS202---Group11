#pragma once
#include "all.h"

class Object
{
protected:
    int _Direction;
    float _Distance, _DistanceSum;
    static int DIVIDE_CONSTANT;

public:
    Coordinate _Pos;
    std::vector<std::string> _STRING;

    void Move(const int &ElapsedTime);
    static void ChangeLevel(const int &level);

    Object();
    virtual ~Object();
};