#pragma once
#include "all.h"

class Game : public Console
{
private:
    std::vector<std::string> WELCOME_STRING, INFO_STRING;
    void InitString();
    void InitPlayer();

public:
    int ElapsedTime;
    int _isPlaying = 0;

    Player _Player;
    VehicleControl _Vehicle;
    AnimalControl _Animal;

    Game();
    ~Game();

    void MoveObj();

    void InitGame();
    void Start();
    void Pause();
    void Crash();
    void isInWelcomeScreen();
};