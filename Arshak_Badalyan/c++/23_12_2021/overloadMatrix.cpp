#include <iostream>

class Matrix {
private:
	int row;
	int col;
	int** matrix;

public:
	Matrix(int row, int col) { 
		this -> setRow(row);
		this -> setCol(col);
		this -> matrix = new int*[this -> getRow()];
	
		for (int i = 0; i < this -> getRow(); ++i){
			matrix[i] = new int[this -> getCol()];
		}
	}

	Matrix(const Matrix& m) {
		this -> row = m.getRow();
		this -> col = m.getCol();
		matrix = new int*[this -> getRow()];
		for (int i = 0; i < this -> getRow(); ++i){
			matrix[i] = new int[this -> getCol()];
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
				matrix[i][j] = random() % 100;
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

	Matrix & operator += (const Matrix &second) { 
		Matrix tmp = Matrix(row, col);
		std::cout << "Operaion overloaing += " << std::endl;
		for (int i = 0; i < this -> getRow(); ++i) {
			for (int j = 0; j < this -> getCol(); ++j) {
				tmp.matrix[i][j] += second.matrix[i][j];
			}	
		}		
		return *this;
	}

	Matrix & operator = (const Matrix &second) { 
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
		delete this->matrix;
	}

};


int main() {
	Matrix matrix1 = Matrix(3, 3);
	Matrix matrix2 = Matrix(3, 3);
	matrix1.getRandom();
	matrix2.getRandom();
	std::cout << "*** First matrix ***"<<std::endl;
	matrix1.display();
	std::cout << "*** Second matrix ***"<<std::endl;
	matrix2.display();
	
	Matrix sum = matrix1 + matrix2; 
	sum.display();
	Matrix sub = matrix1 - matrix2; 
	sub.display();
	Matrix mult = matrix1 * matrix2; 
	mult.display();
	Matrix divid = matrix1 / matrix2; 
	divid.display();
	matrix1 = matrix2;
	matrix1.display();
	matrix1 += matrix2;
	matrix1.display();

	return 0;    
}
