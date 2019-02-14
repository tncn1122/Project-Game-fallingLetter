#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "gConsole.h"
using namespace std;

// thay doi kich thuoc cua khung console
void game::resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// dua con tro den vi tri (x, y)
void game::gotoXY(int x, int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1, y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

// xoa man hinh
void game::clearScr()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// tao man hinh game
void game::createScr()
{
	for (int i = 0; i <= hGame; i++)
	{
		for (int j = 0; j <= 27; j++)
		{
			if (i == 0 && j == 0)
				Map[i][j] = 201;
			else if (i == 0 && j == 27)
				Map[i][j] = 187;
			else if (i == hGame && j == 27)
				Map[i][j] = 188;
			else if (i == hGame && j == 0)
				Map[i][j] = 200;
			else if (i == 0 || i == hGame)
				Map[i][j] = 205;
			else if (j == 0 || j == 27)
				Map[i][j] = 186;
			else 
				Map[i][j] = ' ';
		}
	}
}

// ve man hinh game
void game::drawScr()
{
	for (int i = 0; i <= hGame; i++)
	{
		cout << "\t";
		for (int j = 0; j <= 27; j++)
		{
			if (i == 1 && j != 0 && j != 27)
			{
				Map[i][j] = 65 + j - 1;
			}
			cout << Map[i][j];
		}
		cout << endl;
	}
}

// ve chu
void game::createChr()
{
	posY = 1 + rand() % 25; // random  1 -> 26
	posX = 2;
	key = posY - 1 + 65;
	Map[posX][posY] = key;
	drop = false;
	press = false;
}

// lam chu roi
void game::fallingChr()
{
	if (posX < hGame && !press)
	{
		Map[posX][posY] = ' ';
		posX++;
		if (posX == hGame)
		{
			Map[posX][posY] = '*';
			drop = true;
			press = false;
			life[error--] = ' ';
			score--;
		}
		else
			Map[posX][posY] = key;
	}
		
	if (error < 0)
		lose = true;
}

void game::getKey()
{
	if (kbhit())
	{
		char pressKey = getch();
		if (pressKey == tolower(key))
		{
			press = true;
			drop = true;
			score++;
		}
		else
		{
			life[error--] = ' ';
			score--;
		}
	}
		if (error < 0)
		lose = true;
}

void game::showScore()
{
	cout << "Your Scores: " << score << " ";
}

void game::showLife()
{
	cout << "Your lifes: " << life;
}
