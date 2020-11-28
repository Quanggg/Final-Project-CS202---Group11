#pragma once
#include "game.h"

Game::Game() : Console()
{
    InitString();
}

void Game::Init()
{
    //for (int i = 0; i < 7; i++)
    //  strcpy(screen + (25 + i) * CONSOLE_WIDTH + 53, (char *&)WELCOME[i]);

    //draw welcome at the center
    UpdateScreen(53, 25, WELCOME);

    //teammates
    UpdateScreen(70, CONSOLE_HEIGHT - 1, "19-APCS-1   GROUP 11:  QUANG LE      HUY NGUYEN      HUY PHAN      THANG NGUYEN");
}
void Game::Start()
{
}
void Game::Pause() {}
void Game::Crash() {}
Game::~Game() {}

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
}

void Game::WelcomeScreen()
{
    if (!started && (GetAsyncKeyState((unsigned short)'0') & 0x8000))
        exit(0);
    if (!started && (GetAsyncKeyState((unsigned short)'1') & 0x8000))
        started = 1, CleanScreen();
}