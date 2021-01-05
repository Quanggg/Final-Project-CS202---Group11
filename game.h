#pragma once
#include "all.h"

class Game : public Console
{
public:
    int _ElapsedTime,
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
    std::vector<std::string> CE1, CE2, CE3, CE4, CE5, CE6, CE7;

    Player _Player;
    Vehicle *_Vehicle = NULL;
    Animal *_Animal = NULL;

    const Coordinate OPTION_LOCATION = {100, 10},
                     CONFIRM_LOCATION = {115, 25},
                     LEVEL_UP_LOCATION = {25, 16};

    _LARGE_INTEGER _Time1, _Time2;

    void InitString();
    void InitPlayer();
    void InitTrafficLight();

    void DrawOption(const int &x, const int &y);

    void Welcome();

    void GameTimeControl();
    void TrafficControl();
    void MoveObj();
    void OptionControl();
    void PlayerControl();

    void Setup();
    void LevelUp();
    void Crash();
    bool ConfirmSelect();
    void OptionSelect();
    void ChangeLight();

    std::vector<std::string> getFilename(const std::string &name);

    void loadGameMenu();
    bool loadGame(std::string file);
    void saveGameMenu();
    void saveGame(std::string file);

public:
    bool isWelcome = true;

    Game();
    ~Game();

    void Processing();
    void WelcomeInput();
};