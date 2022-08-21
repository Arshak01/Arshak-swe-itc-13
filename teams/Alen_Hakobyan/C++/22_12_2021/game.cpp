#include <iostream>

class Field {
	private:
		char symbol = ' ';
	public:
		Field() {
			setSymbol(' ');
		}
		Field(char symbol) {
			setSymbol(symbol);
		}
		void setSymbol(char symbol) {
			if (symbol == 'X' || symbol == 'O' || symbol  == ' ') {
				this -> symbol  = symbol;
			}
		}
		char getSymbol() const {
			return this -> symbol;
		}
};

class Player {
	private:
		std::string name;
		char symbol;
		int level;
	public:
		Player(){}
		void setName(std::string name) {
			this -> name = name;
		}
		std::string getName() {
			return this -> name;
		}
		void setSymbol(char symbol) {
			this -> symbol = symbol;
		}
		char getSymbol() const {
			return this -> symbol;
		}
		void setLevel(int level) {
			this -> level = level;
		}
		int getSymbol() {
			return this -> level;
		}
		Player(std::string name, char symbol, int level) {
			setName(name);
			setSymbol(symbol);
			setLevel(level);
		}		
};

class Board {
	private:
		int row = 3;
		int column = 3;
		Field** field = new Field*[this -> row];
	public:
		Board() {
			for(int i = 0; i < this -> column; ++i) {
				field[i]= new Field[this -> column];
			}
		}
		void setRow(int row) {
			this -> row = row;
		}
		void setColumn(int column) {
			this -> column = column;
		}
		int getRow() const {
			return this -> row;
		}
		int getColumn() const {
			return this -> column;
		}	
		bool fill(Player player, int row, int column) {
        	if (row > getRow() || column > getColumn() || field[row][column].getSymbol() != ' ') {
				std::cout << "this fields is already taken" << std::endl;
				return false;
			}
			this -> field[row][column].setSymbol(player.getSymbol());
			return true;
		}

		Board(const Board &b) {
			setRow(b.row);
			setColumn(b.column);
			for (int i = 0; i < b.getRow(); ++i) {
				this -> field[i] = new Field[column];
				for (int j = 0; j < b.getColumn(); ++j) {
					this -> field[i][j].setSymbol(b.field[i][j].getSymbol());
            	}
			}
		}
		void draw() {
			for (int i = 0; i < getRow(); ++i) {
				std::cout << "| ";
				for (int j = 0; j < getColumn(); ++j) {
					std::cout << field[i][j].getSymbol() << " | ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		void cleanMatrixMemory() {
			for (int i = 0; i < getRow(); ++i) {
				delete field[i];
			}
			delete field;
		}
		void cleanMatrix() const {
			for (int i = 0; i < getRow(); ++i) {
				for (int j = 0; j < getColumn(); ++j) {
					this -> field[i][j].setSymbol(' ');
				}
			}
		}
		~Board() {
			cleanMatrixMemory();
		}
};

int main() {
	Player p1 = Player("Player1",'X',1);
	Player p2 = p1;
	p2.setName("Player2");
	p2.setSymbol('O');
	Board b;
	b.fill(p1,0,0);
	b.fill(p2, 1, 0);
	b.fill(p1, 1, 1);
	Board board1 = b;
	board1.cleanMatrix();
	b.draw();
	board1.draw();

	return 0;
}
