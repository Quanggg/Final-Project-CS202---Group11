#include "CPEOPLE.h"
#include <conio.h>

//void goToXY(int x, int y)
//{
//	COORD coord;
//	coord.X = x;
//	coord.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
CGAME::CGAME(int w = 20, int h = 10)
{
	width = w;
	quit = false;
	Player = new CPEOPLE(width);
}
void CGAME::Draw()
{
	system("cls");
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (Player->mX == j && Player->mY == i)
				cout << "Y";
			else
				cout << " ";
		}
		cout << endl;
	}
}
void CGAME::Input()
{
	if (_kbhit())
	{
		char current = _getch();
		if (current == 'a' && Player->mX > 0)
			Player->Left();
		if (current == 'd' && Player->mX < width - 1)
			Player->Right();
		if (current == 'w' && Player->mY > 0)
			Player->Up();
		if (current == 's' && Player->mY < 10 - 1)
			Player->Down();
	}
}
void CGAME::Run()
{
	while (!quit)
	{
		Input();
		Draw();
	}
}

CPEOPLE::CPEOPLE(int width)
{
	mX = width / 2;
	mY = 0;
}
void CPEOPLE::Up()
{
	mY--;
}
void CPEOPLE::Left()
{
	mX--;
}
void CPEOPLE::Right()
{
	mX++;
}
void CPEOPLE::Down()
{
	mY++;
}