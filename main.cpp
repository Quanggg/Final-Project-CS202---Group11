#include "all.h"

main()
{
    Game G;

    while (G.isWelcome)
        G.WelcomeInput();

    while (true)
        G.Processing();
}
