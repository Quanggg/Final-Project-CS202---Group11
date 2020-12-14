#pragma once
#include "game.h"

//
Game::Game() : Console()
{
	Game::InitString();

	Game::Welcome();
}
Game::~Game()
{
	delete _Vehicle;
	delete _Animal;
}

//
void Game::Welcome()
{
	Console::CleanScreenOutput();

	//set level to 1
	_Level = 1;

	//draw game name at the center
	Console::UpdateScreenOutput(33, 5, GAMENAME);

	//draw welcome at the center
	Console::UpdateScreenOutput(53, 25, WELCOME); //draw teammates info
	Console::UpdateScreenOutput(70, CONSOLE_HEIGHT - 1, "19-APCS-1   GROUP 11:  QUANG LE      HUY NGUYEN      HUY PHAN      THANG NGUYEN");
	QueryPerformanceCounter(&_Time2);
}
void Game::WelcomeInput()
{
	if ((GetAsyncKeyState((unsigned short)'0') & 0x8000))
		exit(0);
	if ((GetAsyncKeyState((unsigned short)'1') & 0x8000))
		Game::Setup(), isWelcome = false;
	if ((GetAsyncKeyState((unsigned short)'2') & 0x8000))
		Game::loadGameMenu();
	if ((GetAsyncKeyState((unsigned short)'4') & 0x8000))
		Game::saveGameMenu();
	Console::PrintOutScreen();
	QueryPerformanceCounter(&_Time2);
}

//
void Game::Processing()
{
	Game::GameTimeControl();

	Game::TrafficControl();
	//put map first becase map is the background
	Console::PutMapInScreenOutput();
	//put obj second becase obj's characters can overwrite map's characters
	Game::MoveObj();
	//same reason above
	Console::PutTrafficLightInScreenOutput();

	Game::OptionControl();

	Game::PlayerControl();

	Console::PrintOutScreen();
}

//
void Game::GameTimeControl()
{
	//elapsed time of 1 while loop
	//https://stackoverflow.com/questions/2150291/how-do-i-measure-a-time-interval-in-c
	QueryPerformanceCounter(&_Time1);
	_ElapsedTime = _Time1.QuadPart - _Time2.QuadPart;
	_Time2 = _Time1;
}
void Game::TrafficControl()
{
	//increase _TrafficTime to 15000
	//then change light signal and reset _TrafficTime
	if (_TrafficTime == 15000)
	{
		Game::ChangeLight();
		_TrafficTime = 0;
	}
	_TrafficTime++;
}
void Game::MoveObj()
{
	//Move vehicle
	// if light is green (= 1) then vehicle can move
	if (_Light)
		_Vehicle->Move(_ElapsedTime);
	for (auto i : _Vehicle->_CarLane)
		Console::UpdateScreenOutput(i->_Pos, i->_STRING, true); //car

	for (auto i : _Vehicle->_TruckLane)
		Console::UpdateScreenOutput(i->_Pos, i->_STRING, true); //truck

	//Move animal
	_Animal->Move(_ElapsedTime);
	for (auto i : _Animal->_BirdLane)
		Console::UpdateScreenOutput(i->_Pos, i->_STRING, true); //bird

	for (auto i : _Animal->_DinosaurLane)
		Console::UpdateScreenOutput(i->_Pos, i->_STRING, true); //dinosaur
}
void Game::OptionControl()
{
	//_OptionTime is to prevent program from detect 1 key pressed many times at a time
	Console::UpdateScreenOutput(OPTION_LOCATION, OPTION);
	if (_OptionTime < 1000)
		_OptionTime++;
	if (_OptionTime == 1000)
		Game::OptionSelect();
}
void Game::PlayerControl()
{
	if (_PlayerAllowToMove && _PlayerAllowToMove < 3000)
		_PlayerAllowToMove++;
	else
		_PlayerAllowToMove = 0;

	//check _LevelUP != 0 to prevent show LEVELUP string at the beginning
	if (_LevelUP && _LevelUP < 3000)
	{
		_LevelUP++;
		Console::UpdateScreenOutput(LEVEL_UP_LOCATION, LEVEL_UP);
	}
	else
	{
		if (_PlayerAllowToMove && _PlayerAllowToMove < 3000)
			return;

		_Player.InputFromKeyboard(_ElapsedTime);
		Console::UpdateScreenOutput(_Player._Pos, _Player._STRING, false, true);
	}
}

//

void Game::InitTrafficLight()
{
	_Light = 1;
	_TrafficTime = 0;

	WORD attributes = FOREGROUND_GREEN;
	WriteConsoleOutputAttribute(hConsole, &attributes, 1, {6, 15}, &dwBytesWritten);
	WriteConsoleOutputAttribute(hConsole, &attributes, 1, {5 + MAP_WIDTH - 2, 27}, &dwBytesWritten);
}
void Game::Setup()
{
	delete _Vehicle;
	delete _Animal;

	Console::CleanScreenOutput();
	Game::InitPlayer();
	Game::InitTrafficLight();
	Game::DrawOption(Game::_Level / 10, Game::_Level % 10);

	_Vehicle = new VehicleControl(Game::_Level);
	_Animal = new AnimalControl(Game::_Level);

	_PlayerAllowToMove = 1;
}
void Game::LevelUp()
{
	Game::_Level++;
	Game::DrawOption(Game::_Level / 10, Game::_Level % 10);
	Console::UpdateScreenOutput(LEVEL_UP_LOCATION, LEVEL_UP);
	Game::InitTrafficLight();

	Game::Setup();
	_LevelUP = 1;
	_TrafficTime = 0;
}
void Game::Crash()
{
	Console::UpdateScreenOutput(107, 31, "<Press SPACE BAR to restart level...>");
	while (true)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x80000000)
		{
			Game::Setup();
			break;
		}
		Console::PrintOutScreen();
	}
	QueryPerformanceCounter(&_Time2);
}

bool Game::ConfirmSelect()
{
	Console::UpdateScreenOutput(CONFIRM_LOCATION, CONFIRM);
	Console::PrintOutScreen();
	std::vector<std::string> tmp;
	tmp.assign(3, "             ");
	bool k;
	while (true)
	{
		if ((GetAsyncKeyState((unsigned short)'Y') & 0x8000))
		{
			k = true;
			break;
		}
		if ((GetAsyncKeyState((unsigned short)'N') & 0x8000))
		{
			k = false;
			break;
		}
	}
	Console::UpdateScreenOutput(CONFIRM_LOCATION, tmp);
	Console::PrintOutScreen();
	return k; //no value
}
void Game::OptionSelect()
{
	if ((GetAsyncKeyState((unsigned short)'0') & 0x8000))
	{
		Console::UpdateScreenOutput(118, 24, "-EXIT-");
		if (ConfirmSelect())
			exit(0);

		Console::UpdateScreenOutput(118, 24, "      ");
	}
	if ((GetAsyncKeyState((unsigned short)'1') & 0x8000))
	{
		Console::UpdateScreenOutput(116, 24, "-NEW GAME-");

		if (ConfirmSelect())
		{
			_Level = 1;
			Game::Setup();
		}

		Console::UpdateScreenOutput(116, 24, "           ");
	}
	if ((GetAsyncKeyState((unsigned short)'2') & 0x8000))
	{
		Console::UpdateScreenOutput(116, 24, "-LOAD GAME-");

		if (ConfirmSelect())
			Game::loadGameMenu();

		Console::UpdateScreenOutput(116, 24, "           ");
	}
	if ((GetAsyncKeyState((unsigned short)'4') & 0x8000))
	{
		Console::UpdateScreenOutput(116, 24, "-SAVE GAME-");

		if (ConfirmSelect())
			Game::saveGameMenu();

		Console::UpdateScreenOutput(116, 24, "           ");
	}
	QueryPerformanceCounter(&_Time2);
}

void Game::ChangeLight()
{
	WORD attributes;
	if (_Light)
	{
		attributes = FOREGROUND_RED;
		_Light = 0;
	}
	else
	{
		attributes = FOREGROUND_GREEN;
		_Light = 1;
	}
	WriteConsoleOutputAttribute(hConsole, &attributes, 1, {6, 15}, &dwBytesWritten);
	WriteConsoleOutputAttribute(hConsole, &attributes, 1, {5 + MAP_WIDTH - 2, 27}, &dwBytesWritten);
}

//
void Game::DrawOption(const int &x, const int &y)
{
	for (int i = 1; i < 4; i++)
		for (int j = 27; j < 31; j++)
			OPTION[i][j] = NUM[x][i - 1][j - 27];
	for (int i = 1; i < 4; i++)
		for (int j = 31; j < 35; j++)
			OPTION[i][j] = NUM[y][i - 1][j - 31];
}
void Game::InitPlayer()
{
	_Player._Pos._x = MAP_LOCATION._x + MAP_WIDTH / 2 - 1;
	_Player._Pos._y = MAP_LOCATION._y + MAP_HEIGHT - 3;
	_Player._Pos.SetMax(MAP_LOCATION._x + MAP_WIDTH - 3, MAP_LOCATION._y + MAP_HEIGHT - 3);
	_Player._Pos.SetMin(MAP_LOCATION._x + 1, MAP_LOCATION._y + 1);
}
