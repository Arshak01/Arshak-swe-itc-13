#include <iostream>

class Field {
protected:    
    char mSymbol = ' ';
public:
    void setSymbol(char s) {
        if (s == 'X' || s == 'O' || s == ' ') {
             mSymbol = s;
        } else {
            std::cout << "Wrong symbol" << std::endl; 
        }
    }

    char getSymbol() const{
        return mSymbol;
    }
};

class Player {
    std::string mName;
    int mLevel;
    char mSymbol;
public:    
    void setSymbol(char s) {
        if (s == 'X' || s == 'O') {
             mSymbol = s;
        } else {
            std::cout << "Wrong symbol" << std::endl; 
        }
    }
    char getSymbol() const{
        return mSymbol;
    }

    void setName(std::string n) {
        mName = n;
    }
    std::string getName() const {
        return mName;
    }
    void setLevel(int l) {
        if (mLevel >= 0) {
            mLevel == l;
        }
    }
    int getLevel() const {
        return mLevel;
    }
    Player(std::string n, char s, int l) {
        this->setName(n);
        this->setLevel(l);
        this->setSymbol(s);
        }
};

class Board {
    int mRow = 3;
    int mCol = 3;
    Field** mField;

public:
    void setRow(int r) {
		mRow = r;
		}
	int getRow() {
		return mRow;
		}
	void setCol(int c) {
		mCol = c;
		}
	int getCol() {
		return mCol;
		}
	Board() {
        mField = new Field*[mRow];
		for (int i = 0; i < getRow(); ++i) {
			mField[i] = new Field[mCol];
		    }
		}
    Board(const Board &board) {
        setRow(board.mRow);
        setCol(board.mCol);
        mField = new Field*[mRow];
		for (int i = 0; i < board.mRow; ++i) {
			mField[i] = new Field[mCol];
             for (int j = 0; j < board.mCol; ++j) {
                 mField[i][j].setSymbol(board.mField[i][j].getSymbol());
	    	}
         }
    }
     

   void draw() {
		for (int i = 0; i < getRow(); ++i) {
			std::cout << "| ";
			for (int j = 0; j < getCol(); ++j) {
				std::cout << mField[i][j].getSymbol() << " | ";
			}
			std::cout << std::endl;
			}
            std::cout << std::endl;
		}

    void cleanMatrix() {
        for (int i = 0; i < getRow(); ++i) {
            for (int j = 0; j < getCol(); ++j) {
                 mField[i][j].setSymbol(' ');
            }
        }
    }
    void matrixDestructor() {
		for (int i = 0; i < getRow(); ++i ){
			delete[] mField[i];
		}   
			delete[] mField;
		}  

   bool fill(Player player, int row, int col){
        mField[row][col].setSymbol(player.getSymbol());
        return 0;
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
