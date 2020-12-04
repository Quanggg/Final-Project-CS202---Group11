#include "all.h"
#include <iostream>
#include "game.cpp"

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
            G.WelcomeScreen();
        else
        {
            G.PutMapInScreenOutput();

            G.MoveObj();

            G._Player.InputFromKeyboard(G.ElapsedTime);
            G.UpdateScreenOutput(G._Player._Pos, G._Player._STRING, false, true);
        }
        G.PrintOutScreen();
    }
}