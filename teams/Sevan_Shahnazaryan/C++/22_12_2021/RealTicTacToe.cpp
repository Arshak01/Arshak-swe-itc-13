#include <iostream>
#include <unistd.h>

class Field {
protected:
    char symbol;

public:
    Field() {
        setSymbol(' ');
    }

    Field(const char symbol) {
        setSymbol(symbol);
    }

    void setSymbol(const char symbol) {
        if(symbol == 'X' || symbol == 'O' || symbol == ' ' || symbol >= '1' && symbol <= '9') {
            this->symbol = symbol;
        } else {
            std::cout << "ERROR: Wrong input" << std::endl;
        }
    }

    char getSymbol() const {
        return this->symbol;
    }
};

class Player : public Field {
private:
    std::string name;
    int level;

public:
    Player() { };

    Player(std::string name, char symbol, int level) {
        setName(name);
        setSymbol(symbol);
        setLevel(level);
    }

  	void readName() {
    	std::cin >> this->name;
    }

    void setName(std::string name) {
        this->name = name;
    }

    void setLevel(int level) {
        this->level = level;
    }

    std::string getName() const {
        return this->name;
    }

    int getLevel() const {
        return this->level;
    }
};

class Board {
private:
    Field **matrix = new Field*[3];
    bool gameState = true;

	bool isOccupied(int row, int column) const {
    	return this->matrix[row][column].getSymbol() < '1' ||
          	   this->matrix[row][column].getSymbol() > '9';
    }

  	int isWin(const Player &player) {
  	    int count = 0;
      	int diagonal1 = 3;
        int diagonal2 = 3;
		for(int i = 0; i < 3; ++i) {
        	int row = 3;
            int column = 3;
        	for (int j = 0; j < 3; ++j) {
            	row -= this->matrix[i][j].getSymbol() == player.getSymbol();
              	column -= this->matrix[j][i].getSymbol() == player.getSymbol();
              	count += isOccupied(i, j);
            }
          	diagonal1 -= this->matrix[i][i].getSymbol() == player.getSymbol();
          	diagonal2 -= this->matrix[i][2 - i].getSymbol() == player.getSymbol();
          	if(row * column * diagonal1 * diagonal2 == 0) {
              	return 1;
            }
        }
        if (count == 9) {
            return 2;
        }
      	return 0;
    }

    void fill(const Player &player, int row, int column) {
   		this->matrix[row][column].setSymbol(player.getSymbol());
    }

public:
    Board() {
        for(int i = 0; i < 3; ++i) {
            this->matrix[i] = new Field[3];
        }
      	for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                this->matrix[i][j].setSymbol(i * 3 + (j + 1) + '0');
            }
      	}
    }

    Board(const Board &obj) {
        for(int i = 0; i < 3; ++i) {
            this->matrix[i] = new Field [3];
        }

        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                this->matrix[i][j].setSymbol(obj.matrix[i][j].getSymbol());
            }
        }
    }

    void draw(const Player &player1, const Player &player2) {
        system("clear");
      	std::cout << player1.getName() << ": " << player1.getLevel() << "\t\t";
      	std::cout <<  player2.getLevel() << " :" << player2.getName() << std::endl;
        std::cout << "-------------" << std::endl;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                std::cout << "| " << this->matrix[i][j].getSymbol() << ' ';
            }
            std::cout << '|' << std::endl << "-------------" << std::endl;
        }
    }

    bool readMove(Player &player) {
        std::cout << player.getName() << " enter your move[1-9]: ";
        int move;
        std::cin >> move;
        int row = (move - 1) / 3;
        int column = (move - 1) % 3;
        if (move < 1 || move > 9 || isOccupied(row, column)) {
        	return false;
        }
        fill(player, row, column);
        int check = isWin(player);
        if(check) {
        	if (check == 1) {
                std::cout << player.getName() << " WON THE GAME!!!" << std::endl;
                player.setLevel(player.getLevel() + 1);
        	} else {
                std::cout << "DRAW DRAW DRAW" << std::endl;
        	}
            sleep(5);
            this->gameState = false;
        }
      	return true;
    }

    void startNewGame() {
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                this->matrix[i][j].setSymbol(i * 3 + (j + 1) + '0');
            }
        }
      	this->gameState = true;
    }

    bool getGameState() const {
        return this->gameState;
    }

    ~Board() {
        for(int i = 0; i < 3; ++i) {
            delete[] this->matrix[i];
        }
        delete[] this->matrix;
    }
};



void app() {
  	Player player1("Player1", 'X', 0), player2("Player2", 'O', 0);
	std::cout << "Input player1 name: ";
  	player1.readName();
	std::cout << "Input player2 name: ";
  	player2.readName();
  	Board board;
  	board.draw(player1, player2);
  	int who = 0;
	while(board.getGameState()) {
      	if (who == 0) {
        	while (!board.readMove(player1));
        } else {
        	while (!board.readMove(player2));
        }
        board.draw(player1, player2);
        if (!board.getGameState()) {
            std::cout << "Start new game? [y/n]: ";
            char newGame;
            std::cin >> newGame;
            if (newGame == 'y') {
            	board.startNewGame();
            	board.draw(player1, player2);
            }
        }
      	who = (who + 1) % 2;
    }


}

int main() {
  	app();
    return 0;
}

