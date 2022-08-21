#include <iostream>

class Field {
	private:
		char msymbol = ' ';

	public:
		Field(char symbol) {
			setSymbol(symbol);
		}

        	void setSymbol(char symbol) {
            		if(symbol == 'X' || symbol == 'O') {
                		msymbol = symbol;
			}
			else {
				std::cout << "Enter 'X' or 'O'." << std::endl;
			}
		}
        	char getSymbol() const {
            		return msymbol;
        	}
};

class Player {
	private:
        	std::string mname;
        	char msymbol;
        	int mlevel;
    
    	public:
        	Player(std::string name, char symbol, int level) {
            		setName(name);
            		setSymbol(symbol);
            		setLevel(level);
        	}

		void setLevel(int level) {
            		mlevel = level;
		}
        	int getLevel() const {
            		return mlevel;
        	}
        	void setName(std::string name) {
            		mname = name;
        	}
        	std::string getName() const {
            		return mname;
        	}
        	void setSymbol(char symbol) {
            		if ((symbol == 'X') || (symbol == 'O')) {
                		msymbol = symbol;
            		}
			else {
                		std::cout << "Enter 'X' or 'O'." << std::endl;
            		}
        	}
        	char getSymbol() const {
            		return msymbol;
        	}
};

class Board {
	public:
		Field ** matrix = new Field * [3];
        	Board() {
            		for (int i = 0; i < 3; ++i) {
				matrix[i] = new Field[3];
            		}
        	}

        	~Board() {
            		cleanMatrix();
            		for (int i = 0; i < 3; ++i) {
                		delete[] matrix[i];
            		}
            		delete[] matrix;
        	}

        	bool fill(Player player, int row, int col) {
			if(row > 2 || col > 2){
				return false;
			}
			matrix[row][col].setSymbol(player.getSymbol());
			return true;
		}

		void draw() {
			for (int i = 0; i < 3; ++i) {
				std::cout << "| ";
				for (int j = 0; j < 3; ++j) {
					std::cout << matrix[i][j].getSymbol() << " ";
					std::cout << "| ";
				}
				std::cout << std::endl;
			}
		}

        	void cleanMatrix() {
            		for(int i = 0; i < 3; ++i) {
				for(int j = 0; j < 3; ++j) {
                			matrix[i][j] = ' ';
				}
            		}
        	}
};

int main() {
	Player p1 = Player("Player1",  'X',  1);
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

