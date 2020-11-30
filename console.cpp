#pragma once
#include "console.h"
//#include <cwchar>
Console::Console()
{
    Console::InitMap();
    Console::SetupConsole();
}
Console::~Console()
{
    delete[] screen;
}

void Console::UpdateScreenOutput(const int &x, const int &y, std::vector<std::string> &V)
{
    for (int i = 0; i < V.size(); i++)
        strcpy(screen + (y + i) * CONSOLE_WIDTH + x, (char *&)V[i]);
}
void Console::UpdateScreenOutput(const int &x, const int &y, const std::string &ST)
{
    strcpy(screen + y * CONSOLE_WIDTH + x, (char *&)ST);
}
void Console::UpdateScreenOutput(const Coordinate &pos, std::vector<std::string> &V)
{
    for (int i = 0; i < V.size(); i++)
        strcpy(screen + (pos._y + i) * CONSOLE_WIDTH + pos._x, (char *&)V[i]);
}

void Console::CleanScreenOutput()
{
    for (int i = 0; i < CONSOLE_WIDTH * CONSOLE_HEIGHT; i++)
        screen[i] = ' ';
}
void Console::PrintOutScreen()
{
    screen[CONSOLE_WIDTH * CONSOLE_HEIGHT] = '\0';

    WriteConsoleOutputCharacter(hConsole, (LPCSTR)screen, CONSOLE_WIDTH * CONSOLE_HEIGHT, {0, 0}, &dwBytesWritten);
}

void Console::InitMap()
{
    MAP += " __________________________________________________________________________________________ ";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|------------------------------------------------------------------------------------------|";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|------------------------------------------------------------------------------------------|";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|------------------------------------------------------------------------------------------|";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|------------------------------------------------------------------------------------------|";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|------------------------------------------------------------------------------------------|";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|                                                                                          |";
    MAP += "|__________________________________________________________________________________________|";
}
void Console::PutMapInScreenOutput()
{
    int StartLocation = 2 * CONSOLE_WIDTH + 5;
    for (int i = 0; i < MAP_HEIGHT; i++)
        for (int j = 0; j < MAP_WIDTH; j++)
            screen[StartLocation + CONSOLE_WIDTH * i + j] = MAP[MAP_WIDTH * i + j];
}

void Console::SetupConsole()
{
    Console::CleanScreenOutput();
    SetConsoleActiveScreenBuffer(hConsole);

    HWND consoleWindow = GetConsoleWindow();

    RECT desktop;
    const HWND hDesktop = GetDesktopWindow(); // Get a handle to the desktop window
    GetWindowRect(hDesktop, &desktop);        // Get the size of screen to the variable desktop

    // Screen resolution = desktop.right x desktop.bottom
    // Set console to center of the screen
    MoveWindow(consoleWindow, (desktop.right - SCREEN_WIDTH) / 2, (desktop.bottom - SCREEN_HEIGHT) / 2, SCREEN_WIDTH, SCREEN_HEIGHT, TRUE);

    //Set console to fixed size
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);

    //Change console font 16 and font is Consolas
    /*
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;  // Width of each character in the font
    cfi.dwFontSize.Y = 40; // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    */

    //Hide Cursor
    Console::ShowConsoleCursor(false);
}

void Console::ShowConsoleCursor(bool showFlag)
{
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.dwSize = 2;
    cursorInfo.bVisible = showFlag; // set the cursor visibility

    SetConsoleCursorInfo(hConsole, &cursorInfo);
}