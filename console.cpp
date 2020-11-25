#pragma once
#include "console.h"

Console::Console()
{
    SetConsoleActiveScreenBuffer(hConsole);
    SetupConsole();
}

void Console::write()
{
    WriteConsoleOutputCharacter(hConsole, (LPCSTR)screen, CONSOLE_WIDTH * CONSOLE_HEIGHT, {0, 0}, &dwBytesWritten);
}

Console::~Console()
{
    delete[] screen;
}

void Console::DrawMap()
{
    map += " ____________________________________________________________________";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|--------------------------------------------------------------------|";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|--------------------------------------------------------------------|";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|--------------------------------------------------------------------|";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|--------------------------------------------------------------------|";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|--------------------------------------------------------------------|";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|                                                                    |";
    map += "|____________________________________________________________________|";
}

void Console::SetupConsole()
{
    //Set console to fixed size
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    //style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);

    RECT desktop;
    const HWND hDesktop = GetDesktopWindow(); // Get a handle to the desktop window
    GetWindowRect(hDesktop, &desktop);        // Get the size of screen to the variable desktop
    // Screen resolution = desktop.right x desktop.bottom

    //Change console font 16 and font is Consolas
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;  // Width of each character in the font
    cfi.dwFontSize.Y = 16; // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    // Set console to center of the screen
    MoveWindow(consoleWindow, (desktop.right - SCREEN_WIDTH) / 2, (desktop.bottom - SCREEN_HEIGHT) / 2, SCREEN_WIDTH, SCREEN_HEIGHT, TRUE);
}