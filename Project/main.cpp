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
				gameABC.createLetter(gameABC.posX[i], gameABC.posY[i], gameABC.key[i], gameABC.delayNum[i]);
				gameABC.waiting[i] = true;
			}
			else
			{
				gameABC.num[i]++;
				if (gameABC.num[i] >= gameABC.delayNum[i])
				{
					gameABC.num[i] = 0;
					gameABC.fallingLetter(gameABC.posX[i], gameABC.posY[i], gameABC.key[i]);
					if (gameABC.posX[i] == hGame)
					{
						gameABC.waiting[i] = false;
						gameABC.hit();
					}
				}
				else
					gameABC.showLetter(gameABC.posX[i], gameABC.posY[i], gameABC.key[i]);
			}
		}
		//Sleep(75);
		// in man hinh game
		gameABC.drawScr();
		
		gameABC.getKey();
		
		if (gameABC.levelUp)
			gameABC.updateLevel();

		
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
			
			gameABC.gotoXY(30, 7);
				cout << "YOU LOSE!";
			gameABC.gotoXY(28, 8);
				gameABC.showScore(); 
			gameABC.gotoXY(26, 10);	
				cout << "Thanks for playing!\n\n";
			gameABC.gotoXY(1, 30);
			system("pause");
			break;
			// ket thuc
		}
	}
	return 0;
}
