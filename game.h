#pragma once
#include "all.h"

class Game : public Console
{
private:
    int _ElapsedTime,
        _isPlaying = 0,
        _Level = 1,
        _LevelUP = 0,
        _Light = 1,
        _OptionTime = 0,
        _TrafficTime = 0;

    std::vector<std::string> WELCOME, GAMENAME, LOADMENU, SAVEMENU,
        OPTION, CONFIRM, LEVEL_UP;
    std::vector<std::string> NUM0, NUM1, NUM2, NUM3, NUM4, NUM5, NUM6,
        NUM7, NUM8, NUM9;
    std::vector<std::vector<std::string>> NUM;

    Player _Player;
    VehicleControl *_Vehicle = NULL;
    AnimalControl *_Animal = NULL;

    const Coordinate OPTION_LOCATION = {100, 10},
                     CONFIRM_LOCATION = {115, 25},
                     LEVEL_UP_LOCATION = {25, 16};

    _LARGE_INTEGER _Time1, _Time2;

    void InitString();
    void InitPlayer();

    void DrawOption(const int &x, const int &y);

public:
    bool isWelcome = true;

    bool isLoaded = false;

    Game();
    ~Game();
    void Processing();
    void WelcomeInput();

    void GameTimeControl();
    void TrafficControl();
    void MoveObj();
    void OptionControl();
    void PlayerControl();

    void InitTrafficLight();
    void Setup();
    void Pause();
    void LevelUp();
    void Crash();
    bool ConfirmSelect();
    void OptionSelect();
    void ChangeLight();

    bool loadGameMenu();
    std::vector<std::string> getFilename(const std::string &name);
    bool loadGame(std::string file);
    void saveGameMenu();
    void saveGame(std::string file);
};