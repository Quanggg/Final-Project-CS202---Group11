#ifndef CPEOPLE_h
#define CPEOPLE_h

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

class CPEOPLE
{
public:
	int mX, mY;
	//bool mState;
	CPEOPLE(int width);
	void Up();
	void Left();
	void Right();
	void Down();
};

class CGAME
{
private:
	bool quit;
	int width;
	CPEOPLE* Player;
public:
	CGAME(int w, int h);
	void Draw();
	void Input();
	void Run();
};



void GotoXY(int x, int y);
#endif

