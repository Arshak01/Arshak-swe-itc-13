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
        if(symbol == 'X' || symbol == 'O' || symbol == ' ') {
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

public:
    Board() {
        for(int i = 0; i < 3; ++i) {
            this->matrix[i] = new Field[3];
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

    void fill(const Player &player, int row, int column) {
        this->matrix[row][column].setSymbol(player.getSymbol());
    }

    void cleanMatrix() {
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                this->matrix[i][j].setSymbol(' ');
            }
        }
    }

    void draw() {
        std::cout << "-------------" << std::endl;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                std::cout << "| " << this->matrix[i][j].getSymbol() << ' ';
            }
            std::cout << '|' << std::endl << "-------------" << std::endl;
        }
    }

    ~Board() {
        for(int i = 0; i < 3; ++i) {
            delete[] this->matrix[i];
        }
        delete[] this->matrix;
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
    std::cout << std::endl;
    board1.draw();
    return 0;
}
