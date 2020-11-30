#pragma once
#include <windows.h>
#include <vector>
#include <string>
#include <math.h>
class Player
{
private:
    const int DIVIDE_CONSTANT = 400000;
    float _Distance, _DistanceSum;
    void InitString()
    {
        _STRING.assign(3, "");
        _STRING[0] = " o ";
        _STRING[1] = "/|\\";
        _STRING[2] = "/ \\";
    }
    void Up()
    {
        _Pos.SetY(-floor(_Distance));
    }
    void Left()
    {
        _Pos.SetX(-floor(_Distance));
    }
    void Right()
    {
        _Pos.SetX(floor(_Distance));
    }
    void Down()
    {
        _Pos.SetY(floor(_Distance));
    }

public:
    Coordinate _Pos;
    std::vector<std::string> _STRING;
    Player()
    {
        Player::InitString();
    }

    void InputFromKeyboard(const int &ElapsedTime)
    {
        _DistanceSum = 1.0 * ElapsedTime / DIVIDE_CONSTANT;
        _Distance += _DistanceSum;

        if ((GetAsyncKeyState((unsigned short)'A') & 0x8000))
        {
            Player::Left();
        }
        if ((GetAsyncKeyState((unsigned short)'D') & 0x8000))
        {
            Player::Right();
        }
        if ((GetAsyncKeyState((unsigned short)'W') & 0x8000))
        {
            Player::Up();
        }
        if ((GetAsyncKeyState((unsigned short)'S') & 0x8000))
        {
            Player::Down();
        }
        if (_Distance > 1)
            _Distance = 0;
    }
};