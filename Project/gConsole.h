const int hGame = 30;

class game
{
	private:
		char Map[hGame+1][30];
		int score = 0, error = 2;
		char life[4] = {'O', 'O', 'O'};
		int delayMin = 7, delayMax = 10;
		
	public:
		bool waiting[100] = {0};
		bool press;
		bool lose = false;
		bool levelUp = false;
		char key[100];
		int level = 1;
		int posX[100], posY[100];
		int delayNum[100], num[100] = {0};
		
		void resizeConsole(int width, int height);
		void gotoXY(int x, int y);
		void clearScr();
		void createScr();
		void drawScr();
		void createLetter(int &X, int &Y, char &key, int &delay);
		void fallingLetter(int &posX, int &posY, char &key);
		void showLetter(int posX, int posY, char key);
		void hit();
		void getKey();
		void updateLevel();
		void showScore();
		void showLife();
		void showLevel();
};
