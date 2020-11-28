#pragma once
#include "console.cpp"

class Game : public Console
{
private:
    std::vector<std::string> WELCOME;
    void InitString();

public:
    int started = 0;
    Game();
    void Init();
    void Start();
    void Pause();
    void Crash();
    void WelcomeScreen();
    ~Game();
};