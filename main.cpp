#include "all.h"

int main()
{
    Game G;

    while (G.isWelcome)
        G.WelcomeInput();

    while (true)
        G.Processing();

    return 0;
}
