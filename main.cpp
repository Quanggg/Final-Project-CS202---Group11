#include "all.h"
#include <iostream>
#include "game.cpp"
#include "player.h"
#include <thread>
#include <deque>
#include <chrono>

Game G;

int main()
{
    LARGE_INTEGER time1, time2, timeInterval;
    LARGE_INTEGER Frequency;
    G.InitGame();
    while (1)
    {
        QueryPerformanceFrequency(&Frequency);
        QueryPerformanceCounter(&time1);
        G.ElapsedTime = time1.QuadPart - time2.QuadPart;
        time2 = time1;
        if (!G._isPlaying)
            G.isInWelcomeScreen();
        else
        {
            G.PutMapInScreenOutput();
            G._Vehicle.Move(G.ElapsedTime);
            for (auto i : G._Vehicle._Lane)
                G.UpdateScreenOutput(i->_Pos, i->_STRING);
            G._Player.InputFromKeyboard(G.ElapsedTime);
            G.UpdateScreenOutput(G._Player._Pos._x, G._Player._Pos._y, G._Player._STRING);
        }
        G.PrintOutScreen();
    }
}