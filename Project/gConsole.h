const int hGame = 25;
class game
{
	private:
		char Map[hGame+1][30];
		int posX, posY;
		int score = 0, error = 2;
		char life[4] = {'O', 'O', 'O'};
		
	public:
		bool drop = true;
		bool press;
		bool lose = false;
		char key;
		void resizeConsole(int width, int height);
		void gotoXY(int x, int y);
		void clearScr();
		void createScr();
		void drawScr();
		void createChr();
		void fallingChr();
		void getKey();
		void showScore();
		void showLife();
};
