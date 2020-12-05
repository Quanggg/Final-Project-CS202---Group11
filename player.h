#pragma once
#include "all.h"

class Player
{
private:
    const int DIVIDE_CONSTANT = 930000;
    float _Distance, _DistanceSum;

    void InitString();

    void Up();
    void Left();
    void Right();
    void Down();

public:
    Coordinate _Pos;
    std::vector<std::string> _STRING;

    Player();
    ~Player();

    void InputFromKeyboard(const int &ElapsedTime);
};