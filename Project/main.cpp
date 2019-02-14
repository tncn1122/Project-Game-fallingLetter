#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include "gConsole.h"
using namespace std;

//int x = 15, y = 0;
game gameABC;
int main()
{
	gameABC.resizeConsole(800, 600);
	srand(time(0));
	while (true)
	{
		gameABC.gotoXY(5, 5);
		// tao man hinh game
		gameABC.createScr();
		
		for (int i = 1; i <= gameABC.level; i++)
		{
			if (!gameABC.waiting[i])
			{
				gameABC.createLetter(gameABC.posX[i], gameABC.posY[i], gameABC.key[i]);
				gameABC.waiting[i] = true;
			}
			else
			{
				gameABC.fallingLetter(gameABC.posX[i], gameABC.posY[i], gameABC.key[i]);
				if (gameABC.posX[i] == hGame)
				{
					gameABC.waiting[i] = false;
				}
			}
		}
		Sleep(75);
		// in man hinh game
		gameABC.drawScr();
		
		gameABC.getKey();
		
		
		
		
		gameABC.gotoXY(50, 7);
			gameABC.showScore();
		gameABC.gotoXY(50, 9);
			gameABC.showLife();
		gameABC.gotoXY(50, 11);	
			gameABC.showLevel();
		
		// xoa man hinh
		//gameABC.clearScr();
		if (gameABC.lose)
		{
			system("cls");
			
			cout << "\n\n\n\n\n\t\t\t\tYOU LOSE\n\n\n\n\n\n\n\n";
			return 0;
			// ket thuc
		}
	}
	return 0;
}
