#include "all.h"
#include <iostream>
#include <utility>
#include "game.cpp"
int main()
{
    Game G;
    G.Init();
    while (1)
    {
        if (!G.started)
            G.WelcomeScreen();
        else
        {
            G.PutMapInScreen();

            G.OutScreen();
        }
    }
}
