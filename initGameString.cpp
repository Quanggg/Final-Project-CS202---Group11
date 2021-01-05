#pragma once
#include "game.h"
void Game::InitString()
{
    WELCOME.assign(7, "");
    WELCOME[0] = "____________________WELCOME!___________________";
    WELCOME[1] = "";
    WELCOME[2] = "                 1.  New game";
    WELCOME[3] = "                 2.    Load";
    WELCOME[4] = "                 3.  Settings";
    WELCOME[5] = "                 0.    Exit";
    WELCOME[6] = "               ----------------";

    CONFIRM.assign(3, "");
    CONFIRM[0] = "--Confirm?--";
    CONFIRM[1] = "  [Y] YES";
    CONFIRM[2] = "  [N] NO";

    // copy exactly how number draw, each element must
    // have the same length ( = 4), otherwise missing character on screen
    NUM0.assign(3, "");
    NUM0[0] = " __ ";
    NUM0[1] = "|  |";
    NUM0[2] = "|__|";
    NUM.push_back(NUM0);

    NUM1.assign(3, "");
    NUM1[0] = "    ";
    NUM1[1] = "   |";
    NUM1[2] = "   |";
    NUM.push_back(NUM1);

    NUM2.assign(3, "");
    NUM2[0] = " __ ";
    NUM2[1] = " __|";
    NUM2[2] = "|__ ";
    NUM.push_back(NUM2);

    NUM3.assign(3, "");
    NUM3[0] = " __ ";
    NUM3[1] = " __|";
    NUM3[2] = " __|";
    NUM.push_back(NUM3);

    NUM4.assign(3, "");
    NUM4[0] = "    ";
    NUM4[1] = "|__|";
    NUM4[2] = "   |";
    NUM.push_back(NUM4);

    NUM5.assign(3, "");
    NUM5[0] = " __ ";
    NUM5[1] = "|__ ";
    NUM5[2] = " __|";
    NUM.push_back(NUM5);

    NUM6.assign(3, "");
    NUM6[0] = " __ ";
    NUM6[1] = "|__ ";
    NUM6[2] = "|__|";
    NUM.push_back(NUM6);

    NUM7.assign(3, "");
    NUM7[0] = " __ ";
    NUM7[1] = "   |";
    NUM7[2] = "   |";
    NUM.push_back(NUM7);

    NUM8.assign(3, "");
    NUM8[0] = " __ ";
    NUM8[1] = "|__|";
    NUM8[2] = "|__|";
    NUM.push_back(NUM8);

    NUM9.assign(3, "");
    NUM9[0] = " __ ";
    NUM9[1] = "|__|";
    NUM9[2] = " __|";
    NUM.push_back(NUM9);

    LEVEL_UP.assign(6, "");
    LEVEL_UP[0] = "        ____          ____                 ____    ";
    LEVEL_UP[1] = "  |    |     \\      /|     |        |    ||    |   ";
    LEVEL_UP[2] = "  |    |____  \\    / |____ |        |    ||____|   ";
    LEVEL_UP[3] = "  |    |       \\  /  |     |        |    ||        ";
    LEVEL_UP[4] = "  |____|____    \\/   |____ |____    |____||        ";
    LEVEL_UP[5] = "                                                 ";

    OPTION.assign(11, "");
    OPTION[0] = " _________________________________________";
    OPTION[1] = "|           __     __       __            |";
    OPTION[2] = "|       |  |__\\  /|__|     |  |   |       |";
    OPTION[3] = "|       |__|__ \\/ |__|__   |__|   |       |";
    OPTION[4] = "|                                         |";
    OPTION[5] = "|              1.   New game              |";
    OPTION[6] = "|              2.     Load                |";
    OPTION[7] = "|              3.   Settings              |";
    OPTION[8] = "|              4.     Save                |";
    OPTION[9] = "|              0.     Exit                |";
    OPTION[10] = "|_________________________________________|";

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

    CE1.assign(5, "");
    CE1[0] = "     (        ";
    CE1[1] = "      )       ";
    CE1[2] = "    .  )      ";
    CE1[3] = "     ( \\     ";
    CE1[4] = "    ,---.     ";

    CE2.assign(5, "");
    CE2[0] = "      .(      ";
    CE2[1] = "    (   )     ";
    CE2[2] = "      (       ";
    CE2[3] = "     ) /      ";
    CE2[4] = "    ,---.     ";

    CE3.assign(5, "");
    CE3[0] = "   (  ) (     ";
    CE3[1] = "    ) ( )     ";
    CE3[2] = "    (  )      ";
    CE3[3] = "     ) /      ";
    CE3[4] = "    ,---.     ";

    CE4.assign(5, "");
    CE4[0] = "              ";
    CE4[1] = "              ";
    CE4[2] = "   '.\\|/.'   ";
    CE4[3] = "   (\\   /)   ";
    CE4[4] = "   - -O- -    ";

    CE5.assign(5, "");
    CE5[0] = "              ";
    CE5[1] = "'.  \\ | /  ,'";
    CE5[2] = "  `. `.' ,'   ";
    CE5[3] = " ( .`.|,' .)  ";
    CE5[4] = " - ~ -0- ~ -  ";

    CE6.assign(5, "");
    CE6[0] = ",'  / | \\  '.";
    CE6[1] = "    \\ '  \"  ";
    CE6[2] = " ` . `.' ,'   ";
    CE6[3] = " . `` ,'. \"  ";
    CE6[4] = "   ~ (   ~ -  ";

    CE7.assign(5, "");
    CE7[0] = "              ";
    CE7[1] = "     (  .     ";
    CE7[2] = "      , )     ";
    CE7[3] = "     ( /      ";
    CE7[4] = "    ,---.     ";
}