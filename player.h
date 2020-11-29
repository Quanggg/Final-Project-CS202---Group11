#pragma once
#include <windows.h>
#include <vector>
#include <string>
#include <math.h>
class Player
{
private:
    float _Speed = 50.0f, _Distance;
    void InitString()
    {
        _STRING.assign(3, "");
        _STRING[0] = " o ";
        _STRING[1] = "/|\\";
        _STRING[2] = "/ \\";
    }
    void Up()
    {
        _Pos.SetY(-round(_Distance));
    }
    void Left()
    {
        _Pos.SetX(-round(_Distance));
    }
    void Right()
    {
        _Pos.SetX(round(_Distance));
    }
    void Down()
    {
        _Pos.SetY(round(_Distance));
    }

public:
    Coordinate _Pos;
    std::vector<std::string> _STRING;
    Player()
    {
        Player::InitString();
    }

    void InputFromKeyboard(float ElapsedTime)
    {
        _Distance = _Speed * ElapsedTime;

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
    }
};