#include <iostream>

class Field {
	private:
		char mSymbol = ' ';
	public:
		Field() {}
		Field(char ch) {
			setSymbol(ch);
		}
	
		void setSymbol(char ch) {
			if (ch == 'X' || ch == 'O')
				mSymbol = ch;
		}

		char getSymbol() const {
			return mSymbol;
		}
};

class Player {
	private:
		std::string mName;
		char mSymbol;
		int mLevel;
	public:
		Player() {}
		Player(std::string name, char ch, int level) {
			setName(name);
			setSymbol(ch);
			setLevel(level);
		}

		Player(const Player &player) {
			setName(player.mName);
			setSymbol(player.mSymbol);
			setLevel(player.mLevel);
		}

		void setName(std::string name) {
			mName = name;
		}
		void setSymbol(char ch) {
			if (ch == 'X' || ch == 'O')
				mSymbol = ch;
		}
		void setLevel(int level) {
			mLevel = level;
		}

		std::string getName() const {
			return mName;
		}
		char getSymbol() const {
			return mSymbol;
		}
		int getLevel() const {
			return mLevel;
		}
};

class Board {
	private:
		int mRow = 3;
		int mCol = 3;
		Field** mField;
	public:
		Board() {
			for (int i = 0; i < mCol; ++i)
				mField[i] = new Field[mCol];
		}

		Board(const Board &board) {
			setRow(board.mRow);
			setCol(board.mCol);
			mField = new Field* [mRow];
			mField = board.mField;

			for (int i = 0; i < board.getRow(); ++i) {
				mField[i] = new Field[mCol];
				for (int j = 0; j < board.getCol(); ++j) {
					mField[i][j].setSymbol(board.mField[i][j].getSymbol());
				}
			}
		}

		~Board() {
			cleanMatrix();
		}

		void setRow(int row) {
			mRow = row;
		}
		void setCol(int col) {
			mCol = col;
		}

		int getRow() const {
			return mRow;
		}
		int getCol() const {
			return mCol;
		}

		bool fill(Player player, int row, int col) {
			if (row > getRow() || col > getCol())
				return false;
			mField[row][col].setSymbol(player.getSymbol());
			return true;
		}

		void draw() {
			for (int i = 0; i < getRow(); ++i) {
				std::cout << "|";
				for (int j = 0; j < getCol(); ++j) {
					std::cout << mField[i][j].getSymbol() << " ";
				}
				std::cout << std::endl;
			}
			std::cout << " |" << std::endl;
		}
		
		void cleanMatrix() {
			for (int i = 0; i < getRow(); ++i)
				delete[] mField[i];
			delete[] mField;
		}
};

int main() {
	Player p1 = Player("Player1", 'X', 1);
	Player p2 = p1;
	p2.setName("Player2");
	p2.setSymbol('O');
	Board b;
	b.fill(p1, 0, 0);
	b.fill(p2, 1, 0);
	b.fill(p1, 1, 1);
	Board board1 = b;
	board1.cleanMatrix();
	b.draw();
	board1.draw();
	return 0;
}
