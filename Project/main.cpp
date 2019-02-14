#include <iostream>
#include <Windows.h>
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
		
		
		if (gameABC.drop)
			gameABC.createChr();
			// khoi tao ki tu ngau nhien
		else 
		{
			Sleep(50);
			gameABC.fallingChr();
			// lam roi ki tu do xuong
		}
		
		// in man hinh game
		gameABC.drawScr();
		
		
		gameABC.gotoXY(50, 7);
			gameABC.showScore();
		// in diem
		gameABC.gotoXY(50, 9);
		// in mang
			gameABC.showLife();
			
		// bat ki tu nhap tu ban phim
		gameABC.getKey();
		
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
