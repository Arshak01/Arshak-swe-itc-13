#include <iostream>

template <class T>
class Matrix {
private:
	T** matrix;
	int row;
	int col;
		
public:
	Matrix(int row, int col) {
		this -> setRow(row);
        this -> setCol(col);
		matrix = new T*[this -> getRow()];

		for (int i = 0; i < this -> getRow(); ++i){
			matrix[i] = new T[this -> getCol()];
		}
	}
		
	Matrix(const Matrix& m) {
		this -> row = m.getRow();
		this -> col = m.getCol();
		matrix = new T*[this -> getRow()];
		for (int i = 0; i < this -> getRow(); ++i){
			matrix[i] = new T[this -> getCol()];
		}
		for (int i = 0; i < this -> getRow(); ++i){
			for (int j = 0; j < this -> getCol(); ++j){
				matrix[i][j] = m.matrix[i][j];
			}
		}
	}

	int getRow() const {
		return row;
	}
	void setRow(int row) {
		this -> row = row;
	}

	int getCol() const {
		return col;
	}
	void setCol(int col) {
		this -> col = col;
	}
		
	void getRandom() {
		for (int i = 0; i < this -> getRow(); i++) {
			for (int j = 0; j < this -> getCol(); j++) {
				matrix[i][j] = random() % 50 ;
			}
		}
	}
		
	void display() const {
		for (int i = 0; i < this -> getRow(); ++i) {
			for (int j = 0; j < this -> getCol(); ++j) {
				std::cout << matrix[i][j] << " | ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	Matrix operator + (const Matrix &second) {
		Matrix tmp = Matrix(row, col);
		std::cout << "Operaion overloaing + " << std::endl;
		for (int i = 0; i < this -> getRow(); ++i) {
			for (int j = 0; j < this -> getCol(); ++j) {
				tmp.matrix[i][j] = this -> matrix[i][j] + second.matrix[i][j];
			}
		}
		return tmp;
	}

	Matrix operator - (const Matrix &second) {
		Matrix tmp = Matrix(row, col);
		std::cout << "Operaion overloaing - " << std::endl;
		for (int i = 0; i < this -> getRow(); ++i) {
			for (int j = 0; j < this -> getCol(); ++j) {
				tmp.matrix[i][j] = this -> matrix[i][j] - second.matrix[i][j];
			}
		}
		return tmp;
	}

	Matrix operator * (const Matrix &second) {
		Matrix tmp = Matrix(row, col);
		std::cout << "Operaion overloaing * " << std::endl;
		for (int i = 0; i < this -> getRow(); ++i) {
			for (int j = 0; j < this -> getCol(); ++j) {
				tmp.matrix[i][j] = this -> matrix[i][j] * second.matrix[i][j];
			}
		}
		return tmp;
	}

	Matrix operator / (const Matrix &second) {
		Matrix tmp = Matrix(row, col);
		std::cout << "Operaion overloaing / " << std::endl;
		for (int i = 0; i < this -> getRow(); ++i) {
			for (int j = 0; j < this -> getCol(); ++j) {
				tmp.matrix[i][j] = this -> matrix[i][j] / second.matrix[i][j];
			}
		}
		return tmp;
	}

	Matrix operator += (const Matrix &second) {
		Matrix tmp = Matrix(row, col);
		std::cout << "Operaion overloaing += " << std::endl;
		for (int i = 0; i < this -> getRow(); ++i) {
			for (int j = 0; j < this -> getCol(); ++j) {
				tmp.matrix[i][j] += second.matrix[i][j];
			}
		}
		return *this;
	}

	Matrix operator = (const Matrix &second) {
		Matrix tmp = Matrix(row, col);
		std::cout << "Operaion overloaing = " << std::endl;
		for (int i = 0; i < this -> getRow(); ++i) {
			for (int j = 0; j < this -> getCol(); ++j) {
				tmp.matrix[i][j] = second.matrix[i][j];
			}
		}
		return *this;
	}

	~Matrix() {
		for (int i = 0; i < row; ++i) {
			delete[] matrix[i];
		}
		delete[] this->matrix;
	}
};

int main() {
	Matrix<float> m1 = Matrix<float>(3,3);
	Matrix<float> m2 = Matrix<float>(3,3);
	
	m1.getRandom();
	m2.getRandom();

	std::cout << "*** First matrix ***"<<std::endl;
    m1.display();
    std::cout << "*** Second matrix ***"<<std::endl;
    m2.display();

	Matrix<float> sum = m1 + m2;
    sum.display();
    Matrix<float> sub = m1 - m2;
    sub.display();
    Matrix<float> mult = m1 * m2;
    mult.display();
    Matrix<float> divid = m1 / m2;
    divid.display();
    m1 = m2;
    m1.display();
    m1 += m2;
    m1.display();

	return 0;
}
