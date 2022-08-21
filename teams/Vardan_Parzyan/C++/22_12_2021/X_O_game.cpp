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
        setSymbol(symbol);
    }

    void setSymbol(char symbol) {
        if (symbol == 'x' || symbol == 'o' || symbol == ' ') {
            this->symbol = symbol;
        } else {
            std::cout << "wrong symbol";
        }
    }

    char getSymbol() {
        return this->symbol;
    }
};

class Player {
private:
    std::string name;
    char symbol;
    int level;

public:
    Player() {}

    Player(std::string name, char symbol, int level) {
        setName(name);
        setSymbol(symbol);
        this->level = level;
    }

    Player(const Player &player) {
        setName(player.name);
        setSymbol(player.symbol);
        setLevel(player.level);
    }

    void setName(std::string name) {
        this->name = name;
    }

    std::string getName() const {
        return name;
    }

    void setSymbol(char symbol) {
        if (symbol == 'x' || symbol == 'o') {
            this->symbol = symbol;
        } else {
            std::cout << "wrong symbol";
        }
    }

    char getSymbol() {
        return this->symbol;
    }

    void setLevel(int level) {
        this->level = level;
    }

    int getLevel() {
        return this->level;
    }
};

class Board {
private:
    int row = 3;
    int col = 3;
     Field **matrix = new Field *[row()];
public:
   
    Board() {
        for (int i = 0; i < getRow(); ++i) {
            matrix[i] = new Field[getCol()];
        }
    }

    void setRow(int row) {
        this->row = row;
    }

    void setCol(int col) {
        this->col = col;
    }

    int getRow() const {
        return this->row;
    }

    int getCol() const {
        return this->col;
    }

    bool fill(Player player, int row, int col) {
        if (row > getRow() || col > getCol())
            return false;
        matrix[row][col].setSymbol(player.getSymbol());
        return true;
    }

    Board(const Board &board) {
        setRow(board.row);
        setCol(board.col);

        for (int i = 0; i < board.getRow(); ++i) {
            matrix[i] = new Field[col];
            for (int j = 0; j < board.getCol(); ++j) {
                matrix[i][j].setSymbol(board.matrix[i][j].getSymbol());
            }
        }
    }

    ~Board() {
        cleanMatrixMemory();
    }

    void draw() {
        for (int i = 0; i < getRow(); ++i) {
            std::cout << "| ";
            for (int j = 0; j < getCol(); ++j) {
                std::cout << matrix[i][j].getSymbol() << " | ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void cleanMatrix() const {
        for (int i = 0; i < getRow(); ++i) {
            for (int j = 0; j < getCol(); ++j) {
                this->matrix[i][j].setSymbol(' ');
            }
        }
    }

    void cleanMatrixMemory() {
        for (int i = 0; i < getRow(); ++i)
            delete[] matrix[i];
        delete[] matrix;
    }
};

int main() {
    Player p1 = Player("Player1", 'x', 1);
    Player p2 = p1;
    p2.setName("Player2");
    p2.setSymbol('o');
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
