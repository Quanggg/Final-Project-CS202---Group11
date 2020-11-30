#include "all.h"
#include <iostream>
#include "game.cpp"
#include "people.h"
#include "player.h"
#include <thread>
#include <deque>
#include <chrono>

Game G;
controlVehicle cV;
void Vehicle()
{
    while (1)
    {
        if (G._isPlaying)
        {
            for (auto i : cV.list)
                G.UpdateScreenOutput(i->x, i->y, i->st);
        }
    }
}
int main()
{
    LARGE_INTEGER time1, time2, timeInterval;
    LARGE_INTEGER Frequency;
    //std::thread t1(Vehicle);
    G.InitGame();
    while (1)
    {
        QueryPerformanceFrequency(&Frequency);
        QueryPerformanceCounter(&time1);
        timeInterval.QuadPart = time1.QuadPart - time2.QuadPart;
        time2 = time1;
        if (!G._isPlaying)
            G.isInWelcomeScreen();
        else
        {
            G.PutMapInScreenOutput();
            G._Player.InputFromKeyboard(timeInterval.QuadPart);
            G.UpdateScreenOutput(G._Player._Pos._x, G._Player._Pos._y, G._Player._STRING);
        }
        G.PrintOutScreen();
    }
    //t1.join();
}