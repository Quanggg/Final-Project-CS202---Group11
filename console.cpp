#include "console.h"

//
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

//
void Console::Crash() {}
void Console::LevelUp() {}

//
Console::Console()
{
    Console::InitMap();
    Console::SetupConsole();
}
Console::~Console()
{
    delete[] screen;
}

//
void Console::ShowConsoleCursor(bool showFlag)
{
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.dwSize = 2;
    cursorInfo.bVisible = showFlag; // set the cursor visibility

    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

//
void Console::PutMapInScreenOutput()
{
    int StartLocation = MAP_LOCATION._y * CONSOLE_WIDTH + MAP_LOCATION._x;
    for (int i = 0; i < MAP_HEIGHT; i++)
        for (int j = 0; j < MAP_WIDTH; j++)
            screen[StartLocation + CONSOLE_WIDTH * i + j] = MAP[MAP_WIDTH * i + j];
}
void Console::PutTrafficLightInScreenOutput()
{
    screen[15 * CONSOLE_WIDTH + 6] = 219;

    screen[27 * CONSOLE_WIDTH + 5 + MAP_WIDTH - 2] = 219;
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

//
void Console::UpdateScreenOutput(const int &x, const int &y, std::vector<std::string> &V, const bool &inMap)
{
    if (inMap == false)
        for (int i = 0; i < V.size(); i++)
            strcpy(screen + (y + i) * CONSOLE_WIDTH + x, (char *&)V[i]);
    else
    {
        for (int i = 0; i < V.size(); i++)
        {
            int _LineIndex = (y + i) * CONSOLE_WIDTH;
            int _StartIndex = _LineIndex + x;
            for (int j = _StartIndex, k = 0; j < _StartIndex + V[i].length(); j++, k++)
                if (_LineIndex + MAP_LOCATION._x < j && j < _LineIndex + MAP_LOCATION._x + MAP_WIDTH - 1)
                    screen[j] = V[i][k];
        }
    }
}
void Console::UpdateScreenOutput(const int &x, const int &y, const std::string &ST, const bool &inMap)
{
    if (inMap == false)
        strcpy(screen + y * CONSOLE_WIDTH + x, (char *&)ST);
    else
    {
        int _LineIndex = y * CONSOLE_WIDTH;
        int _StartIndex = _LineIndex + x;
        for (int j = _StartIndex, k = 0; j < _StartIndex + ST.length(); j++, k++)
            if (_LineIndex + MAP_LOCATION._x < j && j < _LineIndex + MAP_LOCATION._x + MAP_WIDTH - 1)
                screen[j] = ST[k];
    }
}
void Console::UpdateScreenOutput(const Coordinate &pos, std::vector<std::string> &V, const bool &inMap, const bool &isPlayer)
{
    if (isPlayer)
    {
        bool _Crash = false;
        bool _LevelUp = false;
        for (int i = 0; i < V.size(); i++)
        {
            if (pos._y < 8)
                _LevelUp = true;
            int _LineIndex = (pos._y + i) * CONSOLE_WIDTH;
            int _StartIndex = _LineIndex + pos._x;
            for (int j = _StartIndex, k = 0; j < _StartIndex + V[i].length(); j++, k++)
            {
                if (screen[j] != ' ' && pos._y != MAP_LOCATION._y + MAP_HEIGHT - 3)
                    _Crash = true;
                screen[j] = V[i][k];
            }
        }
        if (_Crash)
            Crash();
        if (_LevelUp)
            LevelUp();
        return;
    }
    if (inMap == false)
        for (int i = 0; i < V.size(); i++)
            strcpy(screen + (pos._y + i) * CONSOLE_WIDTH + pos._x, (char *&)V[i]);
    else
    {
        for (int i = 0; i < V.size(); i++)
        {
            int _LineIndex = (pos._y + i) * CONSOLE_WIDTH;
            int _StartIndex = _LineIndex + pos._x;
            for (int j = _StartIndex, k = 0; j < _StartIndex + V[i].length(); j++, k++)
                if (_LineIndex + MAP_LOCATION._x < j && j < _LineIndex + MAP_LOCATION._x + MAP_WIDTH - 1)
                    screen[j] = V[i][k];
        }
    }
}