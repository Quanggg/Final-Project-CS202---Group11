#include "all.h"
#include "game.cpp"

main()
{
    Game G;

    while (G.isWelcome)
        G.WelcomeInput();

    while (true)
        G.Processing();
}
