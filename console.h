#pragma once
#include "windows.h"
#include <vector>
#include <string>
#include "coordinate.h"

class Console
{
public:
    const int CONSOLE_WIDTH = 150,
              CONSOLE_HEIGHT = 41,
              MAP_WIDTH = 92,
              MAP_HEIGHT = 36,
              SCREEN_WIDTH = 1218,
              SCREEN_HEIGHT = 700;
    const Coordinate MAP_LOCATION = {5, 2};
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    DWORD dwBytesWritten = 0;
    std::string MAP = "";
    //1 2 2
    void SetupConsole();
    void InitMap();

public:
    Console();
    char *screen = new char[CONSOLE_WIDTH * CONSOLE_HEIGHT + 1];
    void ShowConsoleCursor(bool showFlag);

    void PutMapInScreenOutput();
    void CleanScreenOutput();
    void PrintOutScreen();

    void UpdateScreenOutput(const int &x, const int &y, std::vector<std::string> &V);
    void UpdateScreenOutput(const Coordinate &pos, std::vector<std::string> &V);
    void UpdateScreenOutput(const int &x, const int &y, const std::string &ST);

    ~Console();
};
