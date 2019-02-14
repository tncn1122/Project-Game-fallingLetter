const int hGame = 25;

class game
{
	private:
		char Map[hGame+1][30];
		int score = 0, error = 2;
		char life[4] = {'O', 'O', 'O'};
		
	public:
		bool waiting[100] = {0};
		bool press;
		bool lose = false;
		char key[100];
		int level = 1;
		int posX[100], posY[100];
		
		void resizeConsole(int width, int height);
		void gotoXY(int x, int y);
		void clearScr();
		void createScr();
		void drawScr();
		void createLetter(int &X, int &Y, char &key);
		void fallingLetter(int &posX, int &posY, char &key);
		void getKey();
		void showScore();
		void showLife();
		void showLevel();
};
