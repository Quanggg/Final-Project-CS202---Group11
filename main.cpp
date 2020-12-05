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
/*main()
{
    int i = 0;
    int _TrafficTime = 0;
    while (true)
    {
        QueryPerformanceCounter(&G._Time1);
        G._ElapsedTime = G._Time1.QuadPart - G._Time2.QuadPart;
        G._Time2 = G._Time1;
        if (!G._isPlaying)
            G.WelcomeScreen();
        else
        {
            if (_TrafficTime == 15000)
            {
                G.ChangeLight();
                _TrafficTime = 0;
            }
            _TrafficTime++;
            if (i < 200)
                i++;
            G.UpdateScreenOutput(G.OPTION_LOCATION, G.OPTION);
            G.PutMapInScreenOutput();

            G.MoveObj();
            G.PutTrafficLightInScreenOutput();
            if (G._LevelUP && G._LevelUP < 5000)
            {
                G._LevelUP++;
                G.UpdateScreenOutput(G.LEVEL_UP_LOCATION, G.LEVEL_UP);
            }
            else
            {
                G._Player.InputFromKeyboard(G._ElapsedTime);
                G.UpdateScreenOutput(G._Player._Pos, G._Player._STRING, false, true);
            }
            if (G._LevelUP == 5000)
                G._LevelUP = 0;
            if (i == 200)
                G.OptionSelect();
        }
        G.PrintOutScreen();
    }
}*/
