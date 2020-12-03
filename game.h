#pragma once
#include "console.h"
#include <fstream>
#include <conio.h>

class Game : public Console
{
private:
    std::vector<std::string> WELCOME;
    std::vector<std::string> GAMENAME;
    std::vector<std::string> LOADMENU;
    std::vector<std::string> SAVEMENU;
    void InitString();
    bool isLoaded = false;
public:
    int started = 0;
    Game();
    void Init();
    void Start();
    void Pause();
    void Crash();
    void WelcomeScreen();
    bool loadGameMenu();
    std::vector<std::string> getFilename(const std::string& name);
    bool loadGame(std::string file);
    void saveGameMenu();
    void saveGame(std::string file);
    ~Game();
};