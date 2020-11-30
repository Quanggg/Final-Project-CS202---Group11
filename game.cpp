#pragma once
#include "game.h"

Game::Game() : Console()
{
    Game::InitString();
}

void Game::InitGame()
{
    //for (int i = 0; i < 7; i++)
    //  strcpy(screen + (25 + i) * CONSOLE_WIDTH + 53, (char *&)WELCOME[i]);

    //draw welcome at the center
    Console::UpdateScreenOutput(53, 25, WELCOME_STRING);

    //draw teammates info
    Console::UpdateScreenOutput(70, CONSOLE_HEIGHT - 1, "19-APCS-1   GROUP 11:  QUANG LE      HUY NGUYEN      HUY PHAN      THANG NGUYEN");
}
void Game::Start()
{
}
void Game::Pause() {}
void Game::Crash() {}
Game::~Game() {}

void Game::InitPlayer()
{
    _Player._Pos._x = MAP_LOCATION._x + MAP_WIDTH / 2 - 1;
    _Player._Pos._y = MAP_LOCATION._y + MAP_HEIGHT - 3;
    _Player._Pos.SetMax(MAP_LOCATION._x + MAP_WIDTH - 3, MAP_LOCATION._y + MAP_HEIGHT - 3);
    _Player._Pos.SetMin(MAP_LOCATION._x + 1, MAP_LOCATION._y + 1);
}
void Game::InitString()
{
    WELCOME_STRING.assign(7, "");
    WELCOME_STRING[0] = "____________________WELCOME!___________________";
    WELCOME_STRING[1] = "";
    WELCOME_STRING[2] = "                1.  New game";
    WELCOME_STRING[3] = "                2.  Load game";
    WELCOME_STRING[4] = "                3.  Settings";
    WELCOME_STRING[5] = "                0.    Exit";
    WELCOME_STRING[6] = "               ---------------";
}

void Game::isInWelcomeScreen()
{
    if (!_isPlaying && (GetAsyncKeyState((unsigned short)'0') & 0x8000))
        exit(0);
    if (!_isPlaying && (GetAsyncKeyState((unsigned short)'1') & 0x8000))
        _isPlaying = 1, Console::CleanScreenOutput(), Game::InitPlayer();
}