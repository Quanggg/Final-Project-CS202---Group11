#pragma once
#include "console.cpp"
#include "player.h"
#include "vehicle.h"

class Game : public Console
{
private:
    std::vector<std::string> WELCOME_STRING;
    void InitString();
    void InitPlayer();

public:
    int ElapsedTime;
    int _isPlaying = 0;
    Player _Player;
    Vehicle _Vehicle;
    Game();
    void InitGame();
    void Start();
    void Pause();
    void Crash();
    void isInWelcomeScreen();

    ~Game();
};