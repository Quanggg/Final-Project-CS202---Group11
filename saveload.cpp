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

bool Game::loadGameMenu()
{
    std::string filename;
    CleanScreenOutput();
    std::vector<std::string> files = getFilename("data");
    if (files.size() == 0)
    {
        UpdateScreenOutput(65, 33, "NO SAVED FILES EXIST!");
        return false;
    }
    int curPos = 0;
    CleanScreenOutput();

    UpdateScreenOutput(38, 5, LOADMENU);
    UpdateScreenOutput(36, 13, "<Press ESC to escape...>");
    UpdateScreenOutput(36, 15, "Choose Filename to load: ");

    for (int i = 0; i < (int)files.size(); ++i)
    {
        if (i == curPos)
        {
            UpdateScreenOutput(26, 16 + i, ">> ");
        }
        UpdateScreenOutput(30, 16 + i, files[i]);
    }
    PrintOutScreen();
    while (true)
    {
        if ((GetAsyncKeyState((unsigned short)'W') & 0x8000))
        {
            UpdateScreenOutput(26, 16 + curPos, "    " + files[curPos]);
            curPos--;
            curPos = (curPos + files.size()) % files.size();
            UpdateScreenOutput(26, 16 + curPos, ">>  " + files[curPos]);
            PrintOutScreen();
        }
        if ((GetAsyncKeyState((unsigned short)'S') & 0x8000))
        {
            UpdateScreenOutput(26, 16 + curPos, "    " + files[curPos]);
            curPos++;
            curPos = (curPos + files.size()) % files.size();
            UpdateScreenOutput(26, 16 + curPos, ">>  " + files[curPos]);
            PrintOutScreen();
        }
        if ((GetAsyncKeyState((unsigned short)VK_RETURN) & 0x8000)) //enter
        {
            isLoaded = true;
            loadGame(files[curPos]);
            CleanScreenOutput();
            return true;
        }
        if ((GetAsyncKeyState((unsigned short)VK_ESCAPE) & 0x8000)) //esc
        {
            CleanScreenOutput();
            return false;
        }
    }
    Sleep(200);
    return false;
}

bool Game::loadGame(std::string file)
{
    std::ifstream infile("./data/" + file);
    if (!infile.is_open())
    {
        return false;
    }

    int playerX, playerY;
    infile >> playerX; //load player coordinate
    infile >> playerY;
    //Player.~CPEOPLE();
    //new(&Player) CPEOPLE((playerX, playerY));

    infile.close();
    return true;
}

void Game::saveGameMenu()
{ // get file of cMap ma
    std::string filename;
    CleanScreenOutput();

    UpdateScreenOutput(36, 5, SAVEMENU);
    UpdateScreenOutput(36, 20, "<Press ESC to escape...>");

    UpdateScreenOutput(36, 15, "Input file name to save: ");
    char key;
    while ((key = getch()) != 27)
    {
        switch (key)
        {
        case '\b':
            if (filename.size() != 0)
            {
                filename.pop_back();
                UpdateScreenOutput(61, 15, filename);
                PrintOutScreen();
            }
            break;
        case 13:
            saveGame(filename);
            break;
        default:
            filename.push_back(key);
            UpdateScreenOutput(61, 15, filename);
            PrintOutScreen();
        }
        if (key == 13)
            break;
    }
    CleanScreenOutput();
    PrintOutScreen();
}

void Game::saveGame(std::string file)
{
    std::ofstream outfile("./data/" + file + ".txt");
    //outfile << Player.mX;
    //outfile << Player.mY;

    outfile.close();
}
