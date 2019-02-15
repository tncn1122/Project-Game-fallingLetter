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
	gameABC.gotoXY(5, 5);
	gameABC.createScr();
	gameABC.gotoXY(50, 7);
	gameABC.showScore();
	gameABC.gotoXY(50, 9);
	gameABC.showLife();
	gameABC.gotoXY(50, 11);	
	gameABC.showLevel();
	srand(time(0));
	
	while (true)
	{
		
		// tao man hinh game
		//gameABC.drawScr(10, 6);
		
		for (int i = 1; i <= gameABC.level; i++)
		{
			//bien waiting dung de ngan chuong trinh sinh ra ki tu cho den khi ki tu do duoc bam hoac la cham day khung
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
					if (gameABC.posX[i] >= hGame+5)
					{
						gameABC.waiting[i] = false;
						gameABC.showLetter(gameABC.posX[i], gameABC.posY[i], '*');
						gameABC.hit();
					}
				}
			}
		}
		
		
		Sleep(20);

		// kiem tra ki tu nhap vao
		gameABC.getKey();
		
		//score tang 10 diem thi tang 1 level
		if (gameABC.levelUp)
			gameABC.updateLevel();
		
		//neu diem thay doi thi cap nhat tai man hinh
		if (gameABC.changeScore)
		{
			gameABC.gotoXY(50, 7);
			gameABC.showScore();
			gameABC.gotoXY(50, 9);
			gameABC.showLife();
			gameABC.gotoXY(50, 11);	
			gameABC.showLevel();
			gameABC.changeScore = false;
		}
		
		//sai qua 3 lan
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
