#include "game.h"

//
Game::Game() : Console()
{
    Game::InitString();
}
Game::~Game() {}

//
void Game::MoveObj()
{
    //Move vehicle
    _Vehicle.Move(ElapsedTime);
    for (auto i : _Vehicle._CarLane)
        UpdateScreenOutput(i->_Pos, i->_STRING, true); //car

    for (auto i : _Vehicle._TruckLane)
        UpdateScreenOutput(i->_Pos, i->_STRING, true); //truck

    //Move animal
    _Animal.Move(ElapsedTime);
    for (auto i : _Animal._BirdLane)
        UpdateScreenOutput(i->_Pos, i->_STRING, true); //bird

    for (auto i : _Animal._DinosaurLane)
        UpdateScreenOutput(i->_Pos, i->_STRING, true); //dinosaur
}

//
void Game::InitGame()
{
    //for (int i = 0; i < 7; i++)
    //  strcpy(screen + (25 + i) * CONSOLE_WIDTH + 53, (char *&)WELCOME[i]);

	//draw game name at the center
    UpdateScreen(33, 5, GAMENAME);

    //draw welcome at the center
    Console::UpdateScreenOutput(53, 25, WELCOME_STRING);

    //draw teammates info
    Console::UpdateScreenOutput(70, CONSOLE_HEIGHT - 1, "19-APCS-1   GROUP 11:  QUANG LE      HUY NGUYEN      HUY PHAN      THANG NGUYEN");
}
void Game::Start()
{
}
void Game::Pause() {}
void Game::Crash()
{
    _isPlaying = false;
}

void Game::InitPlayer()
{
    _Player._Pos._x = MAP_LOCATION._x + MAP_WIDTH / 2 - 1;
    _Player._Pos._y = MAP_LOCATION._y + MAP_HEIGHT - 3;
    _Player._Pos.SetMax(MAP_LOCATION._x + MAP_WIDTH - 3, MAP_LOCATION._y + MAP_HEIGHT - 3);
    _Player._Pos.SetMin(MAP_LOCATION._x + 1, MAP_LOCATION._y + 1);
}
void Game::InitString()
{
    WELCOME.assign(7, "");
    WELCOME[0] = "____________________WELCOME!___________________";
    WELCOME[1] = "";
    WELCOME[2] = "                1.  New game";
    WELCOME[3] = "                2.  Load game";
    WELCOME[4] = "                3.  Settings";
    WELCOME[5] = "                0.    Exit";
    WELCOME[6] = "               ---------------";

    GAMENAME.assign(11, "");
    GAMENAME[0] = "      _|_|_|_|  _|_|_|_|  _|_|_|_|  _|_|_|_|  _|_|_|_|  _|  _|      _|  _|_|_|_|";
    GAMENAME[1] = "      _|        _|    _|  _|    _|  _|        _|        _|  _|_|    _|  _|      ";
    GAMENAME[2] = "      _|        _|_|_|_|  _|    _|  _|_|_|_|  _|_|_|_|  _|  _|  _|  _|  _|  _|_|";
    GAMENAME[3] = "      _|        _|  _|    _|    _|        _|        _|  _|  _|    _|_|  _|    _|";
    GAMENAME[4] = "      _|_|_|_|  _|    _|  _|_|_|_|  _|_|_|_|  _|_|_|_|  _|  _|      _|  _|_|_|_|";
    GAMENAME[5] = "";
    GAMENAME[6] = "                        _|_|_|_|  _|_|_|_|  _|_|_|_|  _|_|_|_\\";
    GAMENAME[7] = "                        _|    _|  _|    _|  _|    _|  _|    _|";
    GAMENAME[8] = "                        _|_|_|_|  _|    _|  _|_|_|_|  _|    _|";
    GAMENAME[9] = "                        _|  _|    _|    _|  _|    _|  _|    _|";
   GAMENAME[10] = "                        _|    _|  _|_|_|_|  _|    _|  _|_|_|_/";

   LOADMENU.assign(7, "");
   LOADMENU[0] = "_|        _|_|_|_|  _|_|_|_|  _|_|_|_\\";
   LOADMENU[1] = "_|        _|    _|  _|    _|  _|    _|";
   LOADMENU[2] = "_|        _|    _|  _|_|_|_|  _|    _|  _|     _|  _|_|_|_|  _|      _|  _|    _|";
   LOADMENU[3] = "_|        _|    _|  _|    _|  _|    _|  _|_| _|_|  _|        _|_|    _|  _|    _|";
   LOADMENU[4] = "_|_|_|_|  _|_|_|_|  _|    _|  _|_|_|_/  _|  _| _|  _|_|_|_|  _|  _|  _|  _|    _|";
   LOADMENU[5] = "                                        _|     _|  _|        _|    _|_|  _|    _|";
   LOADMENU[6] = "                                        _|     _|  _|_|_|_|  _|      _|  _|_|_|_|";
   
   SAVEMENU.assign(7, "");
   SAVEMENU[0] = "_|_|_|_|  _|_|_|_|  _|        _|  _|_|_|_| ";
   SAVEMENU[1] = " _|       _|    _|   _|      _|   _|";      
   SAVEMENU[2] = "   _|     _|_|_|_|    _|    _|    _|_|_|_|  _|     _|  _|_|_|_|  _|      _|  _|    _|";
   SAVEMENU[3] = "     _|   _|    _|     _|  _|     _|        _|_| _|_|  _|        _|_|    _|  _|    _|";
   SAVEMENU[4] = "_|_|_|_|  _|    _|      _|_|      _|_|_|_|  _|  _| _|  _|_|_|_|  _|  _|  _|  _|    _|";
   SAVEMENU[5] = "                                            _|     _|  _|        _|    _|_|  _|    _|";
   SAVEMENU[6] = "                                            _|     _|  _|_|_|_|  _|      _|  _|_|_|_|";
}

void Game::isInWelcomeScreen()
{
    if (!_isPlaying && (GetAsyncKeyState((unsigned short)'0') & 0x8000))
        exit(0);
    if (!started && (GetAsyncKeyState((unsigned short)'1') & 0x8000))
        started = 1, CleanScreen();
	if (!started && (GetAsyncKeyState((unsigned short)'2') & 0x8000))
        if(!loadGameMenu())
			Init();
	if (!started && (GetAsyncKeyState((unsigned short)'4') & 0x8000))
		saveGameMenu();
}

std::vector<std::string> Game::getFilename(const std::string& name)
{
	std::vector<std::string> v;
	std::string pattern(name);
	pattern.append("\\*");
	std::wstring stemp = std::wstring(pattern.begin(), pattern.end());
	LPCWSTR sw = stemp.c_str();
	WIN32_FIND_DATAW data;
	HANDLE hFind;
	if ((hFind = FindFirstFileW(sw, &data)) != INVALID_HANDLE_VALUE) {
		do {
			wchar_t* txt = data.cFileName;
			std::wstring ws(txt);
			// your new String
			std::string str(ws.begin(), ws.end());
			if (str[0] == '.') continue;
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
	CleanScreen();
	std::vector <std::string> files = getFilename("data");
	if (files.size() == 0) {
		UpdateScreen(65, 30, "NO SAVED FILES EXIST!");
		return false;
	}
	int curPos = 0;
	CleanScreen();

	UpdateScreen(38, 5, LOADMENU);
	UpdateScreen(36, 13, "<Press ESC to escape...>");
	UpdateScreen(36, 15, "Choose Filename to load: ");

	

	for (int i = 0; i < (int)files.size(); ++i) {
		if (i == curPos) {
			UpdateScreen(26, 16 + i, ">> ");
		}
		UpdateScreen(30, 16 + i, files[i]);
	}
	OutScreen();
	while (true) {
		if ((GetAsyncKeyState((unsigned short)'W') & 0x8000))
		{
			UpdateScreen(26, 16 + curPos, "    " + files[curPos]);
			curPos--;
			curPos = (curPos + files.size()) % files.size();
			UpdateScreen(26, 16 + curPos, ">>  " + files[curPos]);
			OutScreen();
		}
		if ((GetAsyncKeyState((unsigned short)'S') & 0x8000))
		{
			UpdateScreen(26, 16 + curPos, "    " + files[curPos]);
			curPos++;
			curPos = (curPos + files.size()) % files.size();
			UpdateScreen(26, 16 + curPos, ">>  " + files[curPos]);
			OutScreen();
		}
		if ((GetAsyncKeyState((unsigned short)VK_RETURN) & 0x8000)) //enter
		{
			isLoaded = true;
			loadGame(files[curPos]);
			CleanScreen();
			return true;
		}
		if ((GetAsyncKeyState((unsigned short)VK_ESCAPE) & 0x8000)) //esc
		{
			CleanScreen();
			return false;
		}
	}
	Sleep(200);
}

bool Game::loadGame(std::string file) {
	std::ifstream infile("./data/" + file);
	if (!infile.is_open()) {
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

void Game::saveGameMenu() { // get file of cMap ma
	std::string filename;
	CleanScreen();
	
	UpdateScreen(36, 5, SAVEMENU);
	UpdateScreen(36, 20, "<Press ESC to escape...>");

	UpdateScreen(36, 15, "Input file name to save: ");
	char key;
	while ((key = _getch()) != 27) {
		switch (key) {
		case '\b':
			if (filename.size() != 0) {
				filename.pop_back();
				UpdateScreen(61, 15, filename);
				OutScreen();
			}
			break;
		case 13:
			saveGame(filename);
			break;
		default:
			filename.push_back(key);
			UpdateScreen(61, 15, filename);
			OutScreen();
		}
		if (key == 13) break;
	}
	CleanScreen();
	OutScreen();
}

void Game::saveGame(std::string file)
{
	std::ofstream outfile("./data/" + file + ".txt");
	//outfile << Player.mX;
	//outfile << Player.mY;

	outfile.close();
}

    if (!_isPlaying && (GetAsyncKeyState((unsigned short)'1') & 0x8000))
        _isPlaying = 1, Console::CleanScreenOutput(), Game::InitPlayer();
}
