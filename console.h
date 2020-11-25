#pragma once
#include "windows.h"
#include <string>

class Console
{
    const int CONSOLE_WIDTH = 60,
              CONSOLE_HEIGHT = 120,
              MAP_WIDTH = 30,
              MAP_HEIGHT = 30,
              SCREEN_WIDTH = 1240,
              SCREEN_HEIGHT = 600;
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    DWORD dwBytesWritten = 0;
    std::string map = "";

    void SetupConsole();
    void DrawMap();

public:
    char *screen = new char[CONSOLE_WIDTH * CONSOLE_HEIGHT];

    Console();

    void write();

    ~Console();
};