#pragma once
#include "all.h"

class Game : public Console
{
public:
    std::vector<std::string> WELCOME, GAMENAME, LOADMENU, SAVEMENU, INFO;
    std::vector<std::string> NUM0, NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9;
    std::vector<std::vector<std::string>> NUM;

    const Coordinate INFO_LOCATION = {100, 10};

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