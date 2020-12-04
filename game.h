#pragma once
#include "all.h"

class Game : public Console
{
private:
    std::vector<std::string> WELCOME, GAMENAME, LOADMENU, SAVEMENU, INFO;
    void InitString();
    bool isLoaded = false;
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
    void WelcomeScreen();
    bool loadGameMenu();
    std::vector<std::string> getFilename(const std::string &name);
    bool loadGame(std::string file);
    void saveGameMenu();
    void saveGame(std::string file);
};