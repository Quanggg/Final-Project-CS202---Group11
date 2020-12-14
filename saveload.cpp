#pragma once
#include "game.h"

std::vector<std::string> Game::getFilename(const std::string &name)
{
    std::vector<std::string> v;
    std::string pattern(name);
    pattern.append("\\*");
    std::wstring stemp = std::wstring(pattern.begin(), pattern.end());
    LPCWSTR sw = stemp.c_str();
    WIN32_FIND_DATAW data;
    HANDLE hFind;
    if ((hFind = FindFirstFileW(sw, &data)) != INVALID_HANDLE_VALUE)
    {
        do
        {
            wchar_t *txt = data.cFileName;
            std::wstring ws(txt);
            // your new String
            std::string str(ws.begin(), ws.end());
            if (str[0] == '.')
                continue;
            // Show String
            v.push_back(str);
            //Just test !
            //cout << str << endl;
        } while (FindNextFileW(hFind, &data) != 0);
        FindClose(hFind);
    }
    return v;
}

void Game::loadGameMenu()
{
    std::string filename;
    std::vector<std::string> files = getFilename("data");

    if (files.size() == 0 && !isWelcome)
    {
        Console::UpdateScreenOutput(110, 40, "NO SAVED FILES EXIST!");
        return;
    }

    Console::CleanScreenOutput();
    Console::UpdateScreenOutput(38, 4, LOADMENU);
    Console::UpdateScreenOutput(65, 13, "<Press ESC to escape...>");
    Console::UpdateScreenOutput(65, 15, "Choose Filename to load: ");
    if (files.size() == 0)
    {
        Console::UpdateScreenOutput(67, 16, "NO SAVED FILES EXIST!");
        Console::UpdateScreenOutput(110, 40, "                     ");
    }
    else
    {
        int curPos = 0;

        for (int i = 0; i < (int)files.size(); ++i)
        {
            if (i == curPos)
            {
                Console::UpdateScreenOutput(66, 16 + i, ">> ");
            }
            Console::UpdateScreenOutput(70, 16 + i, files[i]);
        }
        bool w_pressed = false, s_pressed = false;
        while (true)
        {
            if ((GetAsyncKeyState((unsigned short)'W') & 0x8000))
                w_pressed = true;
            else if (w_pressed)
            {
                w_pressed = false;
                Console::UpdateScreenOutput(66, 16 + curPos, "    " + files[curPos]);
                curPos--;
                curPos = (curPos + files.size()) % files.size();
                Console::UpdateScreenOutput(66, 16 + curPos, ">>  " + files[curPos]);
                Console::PrintOutScreen();
            }
            if ((GetAsyncKeyState((unsigned short)'S') & 0x8000))
                s_pressed = true;
            else if (s_pressed)
            {
                s_pressed = false;
                Console::UpdateScreenOutput(66, 16 + curPos, "    " + files[curPos]);
                curPos++;
                curPos = (curPos + files.size()) % files.size();
                Console::UpdateScreenOutput(66, 16 + curPos, ">>  " + files[curPos]);
                Console::PrintOutScreen();
            }
            if ((GetAsyncKeyState((unsigned short)VK_RETURN) & 0x8000)) //enter
            {
                if (Game::loadGame(files[curPos]) == false)
                    Console::UpdateScreenOutput(40, 16 + curPos, "Cannot load file ---->");
                else
                {
                    Console::CleanScreenOutput();
                    isWelcome = false;
                    return;
                }
            }
            if ((GetAsyncKeyState((unsigned short)VK_ESCAPE) & 0x8000)) //esc
            {
                Console::CleanScreenOutput();
                if (isWelcome == true)
                    Game::Welcome();
                return;
            }
            Console::PrintOutScreen();
        }
    }
}

bool Game::loadGame(std::string file)
{
    std::ifstream f("./data/" + file);
    if (!f.is_open())
        return false;

    f >> _Level;
    Game::DrawOption(_Level / 10, _Level % 10);

    Game::InitPlayer();
    f >> _Player._Pos._x >> _Player._Pos._y;

    f >> _Light;
    _Light = !_Light;
    Game::ChangeLight();
    f >> _TrafficTime;

    delete _Vehicle;
    delete _Animal;
    _Vehicle = new VehicleControl(Game::_Level, false);
    _Animal = new AnimalControl(Game::_Level, false);

    int n, x, y;
    Vehicle *v;
    Animal *a;

    f >> n;
    for (int i = 0; i < n; i++)
    {
        f >> x >> y;
        v = new Car(x, y);
        _Vehicle->_CarLane.push_back(v);
    }
    f >> n;
    for (int i = 0; i < n; i++)
    {
        f >> x >> y;
        v = new Truck(x, y);
        _Vehicle->_TruckLane.push_back(v);
    }
    f >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        f >> x >> y;
        a = new Bird(x, y);
        _Animal->_BirdLane.push_back(a);
    }
    f >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        f >> x >> y;
        a = new Dinosaur(x, y);
        _Animal->_DinosaurLane.push_back(a);
    }
    f.close();
    return true;
}

void Game::saveGameMenu()
{ // get file of cMap ma
    std::string filename;

    Console::UpdateScreenOutput(110, 31, "<Press ESC to escape...>");
    Console::UpdateScreenOutput(110, 30, "<Press ENTER to save...>");
    Console::UpdateScreenOutput(112, 25, "Enter name to save: ");

    char key = ' ';
    short x = 115, y = 26;

    Console::ShowConsoleCursor(true);
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    SetConsoleCursorPosition(hConsole, {x, y});
    do
    {
        switch (key)
        {
        case '\b':
            if (filename.size() != 0)
            {
                filename.pop_back();
                Console::UpdateScreenOutput(115, 26, filename);
                x--;
                Console::PrintOutScreen();
            }
            break;
        case 13:
            Game::saveGame(filename);
            break;
        default:
            filename.push_back(key);
            Console::UpdateScreenOutput(115, 26, filename);
            x++;
            Console::PrintOutScreen();
        }
        if (key == 13)
            break;
        SetConsoleCursorPosition(hConsole, {x, y});
    } while ((key = getch()) != 27);
    Console::ShowConsoleCursor(false);
    Console::UpdateScreenOutput(110, 31, "                        ");
    Console::UpdateScreenOutput(110, 30, "                        ");
    Console::UpdateScreenOutput(112, 25, "                        ");
    Console::UpdateScreenOutput(115, 26, "                            ");
}

void Game::saveGame(std::string file)
{
    std::ofstream f("./data/" + file + ".txt");
    if (!f.is_open())
    {
        mkdir("./data");
        f.open("./data/" + file + ".txt");
    }

    f << _Level << '\n';
    f << _Player._Pos._x << " " << _Player._Pos._y << '\n';

    f << _Light << '\n';
    f << _TrafficTime << '\n';

    f << _Vehicle->_CarLane.size() << '\n';
    for (auto i : _Vehicle->_CarLane)
        f << i->_Pos._x << " " << i->_Pos._y << '\n';
    f << _Vehicle->_TruckLane.size() << '\n';
    for (auto i : _Vehicle->_TruckLane)
        f << i->_Pos._x << " " << i->_Pos._y << '\n';

    f << _Animal->_BirdLane.size() << '\n';
    for (auto i : _Animal->_BirdLane)
        f << i->_Pos._x << " " << i->_Pos._y << '\n';
    f << _Animal->_DinosaurLane.size() << '\n';
    for (auto i : _Animal->_DinosaurLane)
        f << i->_Pos._x << " " << i->_Pos._y << '\n';

    f.close();
}
