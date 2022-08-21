#include <iostream>
#include <string>

class Field {
private:
    char symbol = ' ';

public:
    Field() {
        setSymbol(' ');
    }

    Field(char symbol) {
        this->setSymbol(symbol);
    }

    void setSymbol(char symbol) {
        if (symbol == ' ' || symbol == 'x' || symbol == 'o') {
            this->symbol = symbol;
        }
    }

    char getSymbol() const {
        return this->symbol;
    }
};

class Player {
private:
    std::string name;
    int level;
    char symbol;
public:
    Player(std::string name, char ch, int level) {
        this->setName(name);
        this->setSymbol(ch);
        this->setLevel(level);
    }

    Player(const Player &p) {
        setName(p.name);
        setSymbol(p.symbol);
        setLevel(p.level);
    }

    void setName(std::string name) {
        this->name = name;
    }

    std::string getName() const {
        return this->name;
    }

    void setSymbol(char symbol) {
        this->symbol = symbol;
    }

    char getSymbol() const {
        return this->symbol;
    }

    void setLevel(int level) {
        if (level >= 0) {
            this->level = level;
        } else {
            std::cout << "Level must be positive or 0 number " << std::endl;
        }
    }

    int getLevel() const {
        return this->level;
    }
};

class Board {
private:
	int row = 3;
	int col = 3;
	Field **field = new Field *[this->getRow()];
    
public:
	Board() {
		for (int i = 0; i < this->getCol(); ++i) {
			field[i] = new Field[this->getCol()];
		}
	}

    Board(const Board &b) {
        setRow(b.row);
        setCol(b.col);

        for (int i = 0; i < b.row; ++i) {
            this->field[i] = new Field[col];
            for (int j = 0; j < b.col; ++j) {
                this->field[i][j].setSymbol(b.field[i][j].getSymbol());
            }
        }
    }

    void setRow(int row) {
        this->row = row;
    }

    int getRow() {
        return this->row;
    }

    void setCol(int col) {
        this->col = col;
    }

    int getCol() {
        return this->col;
    }

    bool fill(Player player, int row, int column) const {
        if (row > this->row || column > this->col || field[row][column].getSymbol() != ' ') {
            return false;
        }
        this->field[row][column].setSymbol(player.getSymbol());
        return true;
    }

    void score() {
        std::cout << "##################" << std::endl;
        std::cout << "Player 1 : " << " - " << " " << " - " << std::endl;
        std::cout << "Player 2 : " << " - " << " " << " - " << std::endl;
        std::cout << "##################" << std::endl;
    }

	void draw() {
    	score();
        std::cout << std::endl;
    	for (int i = 0; i < this -> getRow(); ++i) {
        	if(i == 1 || i == 2) {
            	std::cout << "-----------" << std::endl;
            }
            for (int j = 0; j < this -> getCol(); ++j) {
            	if(j == 1 || j == 2) {
                	std::cout << "|";
               	}
               	std::cout << " " <<  field[i][j].getSymbol() << " ";
            }
            std::cout << std::endl;
		}
        std::cout << std::endl;
	}

    void cleanMatrix() const {
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->col; ++j) {
                this->field[i][j].setSymbol(' ');
            }
        }
    }

    void cleanMatrixMemory() {
        for (int i = 0; i < this->getRow(); ++i) {
            delete[] field[i];
        }
        delete field;
    }

    ~Board() {
        cleanMatrixMemory();
    }
};

int main() {
	std::cout << "***** TIC-TAC-TOE ***** " << std::endl;
	Player player1 = Player("Player1", 'x', 1);
	Player player2 = player1;
	player2.setName("Player2");
	player2.setSymbol('o');
	Board b;
	b.fill(player1, 0, 0);
	b.fill(player2, 1, 0);
	b.fill(player1, 1, 1);
	Board board1 = b;
	board1.cleanMatrix();
	b.draw();
	board1.draw();
    
	return 0;
}
