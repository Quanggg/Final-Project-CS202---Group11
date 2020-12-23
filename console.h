#pragma once
#include "all.h"

class Console
{
private:
    std::string MAP = "";
    char *screen = new char[CONSOLE_WIDTH * CONSOLE_HEIGHT + 1];

    void SetupConsole();
    void InitMap();

public:
    static const int CONSOLE_WIDTH = 150,
                     CONSOLE_HEIGHT = 41,
                     MAP_WIDTH = 92,
                     MAP_HEIGHT = 36,
                     SCREEN_WIDTH = 1218,
                     SCREEN_HEIGHT = 700;
    const Coordinate MAP_LOCATION = {5, 2};

    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    DWORD dwBytesWritten = 0;

    Console();
    ~Console();

    void ShowConsoleCursor(bool showFlag);

    void PutMapInScreenOutput();
    void PutTrafficLightInScreenOutput();
    void CleanScreenOutput();
    void PrintOutScreen();

    void UpdateScreenOutput(const int &x, const int &y, std::vector<std::string> &V, const bool &inMap = false);
    void UpdateScreenOutput(const Coordinate &pos, std::vector<std::string> &V, const bool &inMap = false, const bool &isPlayer = false);
    void UpdateScreenOutput(const int &x, const int &y, const std::string &ST, const bool &inMap = false);

    virtual void Crash();
    virtual void LevelUp();
};
