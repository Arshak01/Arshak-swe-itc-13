#include <iostream>

template <typename T>
class Matrix {
private:

	int row, col;
	T** matrix;

public:
    
	Matrix(int row, int col) { 
		matrix = new T*[row];
		for (int i = 0; i < row; ++i){
			matrix[i] = new T[col];
			this->row = row; this->col = col;
		}
	}
       
	Matrix(const Matrix& A) {
		row = A.getRow();
		col = A.getCol();
		matrix = new int*[row];
		for (int i = 0; i < row; ++i){
			matrix[i] = new int[col];
		}
		for (int i = 0; i < row; ++i){
			for (int j = 0; j < col; ++j){
				matrix[i][j] = A.matrix[i][j];
			}
		} 
		//std::cout << "CC Call" << std::endl;
	}

	int getRow() const {
		return row;
	}
	
	int getCol(void) const {
		return col;
	}
   
	void matrixRandom() {
		for (int i = 0; i < getRow(); i++) {
			for (int j = 0; j < getCol(); j++) {
				matrix[i][j] = rand() % 9 + 1;
			}
		}
	}

	void print() const {
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				std::cout << matrix[i][j] << "  ";
			}
			std::cout << std::endl;
		}
			std::cout << std::endl;
	}


	Matrix operator + (const Matrix &second) { 
		Matrix tmp = Matrix(row, col);
		std::cout << "↓↓'+'↓↓\n";
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				tmp.matrix[i][j] = this->matrix[i][j] + second.matrix[i][j];
			}	
		}		
		return tmp;
	}
   
	Matrix operator - (const Matrix &second) { 
		Matrix tmp = Matrix(row, col);
		std::cout << "↓↓'-'↓↓\n";
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				tmp.matrix[i][j] = this->matrix[i][j] - second.matrix[i][j];
			}	
		}		
		return tmp;
	}
   
	Matrix operator * (const Matrix &second) { 
		Matrix tmp = Matrix(row, col);
		std::cout << "↓↓'*'↓↓\n";
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				tmp.matrix[i][j] = this->matrix[i][j] * second.matrix[i][j];
			}	
		}		
		return tmp;
	}
	
	Matrix& operator = (const Matrix &second) {       
		std::cout << "↓↓'='↓↓\n";
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				this->matrix[i][j] = second.matrix[i][j];
			}
		}		
		return *this;
	}
	
	Matrix& operator += (const Matrix &second) {       
		std::cout << "↓↓'+='↓↓\n";
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				this->matrix[i][j] += second.matrix[i][j];
			}
		}		
		return *this;
	}
    
 	~Matrix() {
		for (int i = 0; i < row; ++i) {
			delete[] matrix[i]; 
		}         
		delete[] this->matrix;
		//std::cout << "Destructor operator called\n";
	}

};


int main() {
	Matrix<int> matrix1 = Matrix<int>(3, 4);
	Matrix<int> matrix2 = Matrix<int>(3, 4);
	matrix1.matrixRandom();
	matrix2.matrixRandom();
	std::cout << "↓↓ First matrix ↓↓"<<std::endl;
	matrix1.print();
	std::cout << "↓↓ Second matrix ↓↓"<<std::endl;
	matrix2.print();
	Matrix<int> action = matrix1 + matrix2; 
	action.print();
	Matrix<int> action1 = matrix1 - matrix2;
	action1.print();
	Matrix<int> action2 = matrix1 * matrix2; 
	action2.print();
	matrix1 = matrix2;
	matrix1.print();
	matrix1 += matrix2;
	matrix1.print();

	return 0;    
}
