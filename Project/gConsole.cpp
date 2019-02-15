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
			if (i == 0 && j == 0)				//up left
				Map[i][j] = 201;
			else if (i == 0 && j == 27)			//up right
				Map[i][j] = 187;
			else if (i == hGame && j == 27)		//down right
				Map[i][j] = 188;
			else if (i == hGame && j == 0)		//down left
				Map[i][j] = 200;
			else if (i == 0 || i == hGame)		//vertical line
				Map[i][j] = 205;
			else if (j == 0 || j == 27)			//horizontal line
				Map[i][j] = 186;
			else 
				Map[i][j] = ' ';
				
			if (i == 1 && j > 0 && j < 27)		//alphabet
				Map[i][j] = j + 64;
		}
	}
	
	for (int i = 0; i <= hGame; i++)
	{
		cout << "\t";
		for (int j = 0; j <= 27; j++)
		{
			cout << Map[i][j];
		}
		cout << endl;
	}
	
}

// ve man hinh game
void game::drawScr(int x, int y)
{
	for (int i = 2; i < hGame-1; i++)
	{
		gotoXY(x, y+i);
		for (int j = 1; j < 27; j++)
		{
			cout << Map[i][j];
		}
	}
}

// sinh chu
void game::createLetter(int &posX, int &posY, char &key, int &delay)
{
	posY = 1 + rand() % 25 + 9; // random  1 -> 26
	posX = 7;
	key = posY - 1 + 65 - 9;
	showLetter(posX, posY, key);
	delay = delayMin + rand() % delayMax;
}

// lam chu roi
void game::fallingLetter(int &posX, int &posY, char &key)
{
	if (posX < hGame+5 && !press)
	{
		showLetter(posX, posY, ' ');
		posX++;
		showLetter(posX, posY, key);
	}
}

// in ki tu tai vi tri x, y
void game::showLetter(int posX, int posY, char key)
{
	gotoXY(posY, posX);
	cout << key;
}

// kiem tra ki tu nhap tu ban phim
void game::getKey()
{
	if (kbhit())
	{
		char pressKey = getch();
		bool fail = false; // bien kiem tra ki tu nhap tu ban phim co khac voi ki tu tren man hinh hay khong
		for (int i = 1; i <= level; i++)
		{
			if (tolower(pressKey) == tolower(key[i]))
			{
				//neu nhap dung thi xoa ki tu do tren man hinh va thay doi bien waiting de tiep tuc sinh ki tu khac
				waiting[i] = false;
				showLetter(posX[i],posY[i],' ');		
				changeScore = true;
				score++;
				
				// cu 10 diem thi tang 1 level
				if (score%10 == 0)	
					levelUp = true;
					
				fail = false;
				break;
			}
			else
				fail = true;
		}
		
		// neu ki tu nhap vao khong trung voi bat ki ki tu dang co tren man hinh thi tru life
		if (fail)
		{
			hit();
		}
	}
}

//khi fail
void game::hit()
{
	//error = 2, la so mang ban dau
	if (error >= 0)
	{
		life[error] = ' ';
		error--;
	}
	else
		lose = true;
		
	changeScore = true;	
}

// ham tang level
void game::updateLevel()
{
	// delayMin va delayMax la pham vi random toc do delay chu roi, so cang thap thi chu roi cang nhanh
	// moi lan tang 1 level thi delayMin giam 1
	// tang 2 level thi delayMax giam 1
	level++;
	levelUp = false;
	if (delayMin >= 0)
		delayMin--;
	if (delayMin&1 || delayMin == 0 && delayMax > 0)
		delayMax--;
}


void game::showScore()
{
	cout << "Your Scores: " << score << " ";
}

void game::showLife()
{
	cout << "Your lifes: " << life;
}

void game::showLevel()
{
	cout << "Your Levels: " << level;
}
