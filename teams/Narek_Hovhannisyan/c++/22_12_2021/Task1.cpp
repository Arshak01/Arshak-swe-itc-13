#include <iostream>

class Field {
private:
    char symbol = ' ';

public:
    Field() {
        setSymbol(' ');
    }

    Field(char ch) {
        setSymbol(ch);
    }

    char getSymbol() const {
        return this->symbol;
    }

    void setSymbol(char ch) {
        if (ch == 'X' || ch == 'O' || ch == ' ') {
            this->symbol = ch;
        }
    }
};


class Player {
private:
    std::string name;
    char symbol;
    int level;
public:
    Player() {}

    Player(std::string name, char ch, int l) {
        setName(name);
        setSymbol(ch);
        setLevel(l);
    }

    Player(const Player &p) {
        setName(p.name);
        setSymbol(p.symbol);
        setLevel(p.level);
    }

    std::string getName() const {
        return this->name;
    }

    void setName(std::string n) {
        this->name = n;
    }

    char getSymbol() const {
        return this->symbol;
    }

    void setSymbol(char ch) {
        if (ch == 'X' || ch == 'O') {
            this->symbol = ch;
        }
    }

    int getLevel() const {
        return this->level;
    }

    void setLevel(int l) {
        this->level = l;
    }

};

class Board {
private:
    int row = 3;
    int column = 3;

public:
    Field **fields = new Field *[this->row];

    Board() {
        for (int i = 0; i < this->column; ++i) {
            fields[i] = new Field[this->column];
        }
    }

    Board(const Board &b) {
        setRow(b.row);
        setColumn(b.column);

        this->fields = new Field *[row];

        for (int i = 0; i < b.getRow(); ++i) {
            this->fields[i] = new Field[column];
            for (int j = 0; j < b.getColumn(); ++j) {
                this->fields[i][j].setSymbol(b.fields[i][j].getSymbol());
            }
        }
    }

    ~Board() {
        cleanMatrixMemory();
    }

    int getRow() const {
        return this->row;
    }

    void setRow(int r) {
        this->row = r;
    }

    int getColumn() const {
        return this->column;
    }

    void setColumn(int c) {
        this->column = c;
    }

    bool fill(Player player, int row, int column) const {
        if (row > getRow() || column > getColumn() || fields[row][column].getSymbol() != ' ') {
            std::cout << "this fields is already taken" << std::endl;
            return false;
        }
        this->fields[row][column].setSymbol(player.getSymbol());
        return true;
    }

    void draw() const {
        for (int i = 0; i < getRow(); ++i) {
            std::cout << "| ";
            for (int j = 0; j < getColumn(); ++j) {
                std::cout << this->fields[i][j].getSymbol() << " | ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void cleanMatrix() const {
        for (int i = 0; i < getRow(); ++i) {
            for (int j = 0; j < getColumn(); ++j) {
                this->fields[i][j].setSymbol(' ');
            }
        }
    }

    void cleanMatrixMemory() const {
        for (int i = 0; i < getRow(); ++i) {
            delete[] fields[i];
        }
        delete[] fields;
    }
};

int main() {
    // X is uppercase x letter
    // O is uppercase o letter
    Player p1 = Player("Player1", 'X', 1);
    Player p2 = p1;
    p2.setName("Player2");
    p2.setSymbol('O');
    Board b;
    b.fill(p1, 0, 0);
    b.fill(p2, 1, 0);
    b.fill(p1, 1, 1);
    b.fill(p1, 0, 0);
    b.fill(p2, 0, 0);
    Board board1 = b;
    board1.cleanMatrix();
    b.draw();
    board1.draw();
    // matrix memory is being cleaned in destructor
    return 0;
}
