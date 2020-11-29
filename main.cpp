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
    LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
    LARGE_INTEGER Frequency;

    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&StartingTime);

    // Activity to be timed

    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;

    //
    // We now have the elapsed number of ticks, along with the
    // number of ticks-per-second. We use these values
    // to convert to the number of elapsed microseconds.
    // To guard against loss-of-precision, we convert
    // to microseconds *before* dividing by ticks-per-second.
    //

    ElapsedMicroseconds.QuadPart *= 1000000;
    ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;
    std::thread t1(Vehicle);
    G.InitGame();
    auto tp1 = std::chrono::system_clock::now();
    auto tp2 = std::chrono::system_clock::now();
    while (1)
    {
        tp2 = std::chrono::system_clock::now();
        std::chrono::duration<float> elapsedTime = tp2 - tp1;
        tp1 = tp2;
        float fElapsedTime = elapsedTime.count();
        if (!G._isPlaying)
            G.isInWelcomeScreen();
        else
        {
            G.PutMapInScreenOutput();
            G._Player.InputFromKeyboard(fElapsedTime);
            G.UpdateScreenOutput(G._Player._Pos._x, G._Player._Pos._y, G._Player._STRING);
        }
        G.PrintOutScreen();
    }
    t1.join();
}