#include "all.h"
#include <iostream>
#include <utility>
#include "game.cpp"
#include "people.h"
#include <thread>
#include <deque>

Game G;
controlVehicle cV;
void Vehicle()
{
    while (1)
    {
        if (G.isPlaying)
        {
            for (auto i : cV.list)
                G.UpdateScreen(i->x, i->y, i->st);
        }
    }
}
int main()
{
    std::thread t1(Vehicle);
    G.Init();
    while (1)
    {
        if (!G.isPlaying)
            G.WelcomeScreen();
        else
        {
            G.PutMapInScreen();
        }
        G.OutScreen();
    }
    t1.join();
}