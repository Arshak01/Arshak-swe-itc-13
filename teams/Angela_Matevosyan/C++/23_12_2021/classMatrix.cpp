#include <iostream>

template <class T>
class Matrix {
private:
	 int mRow = 3;
	 int mCol = 3;
	 T** matrix;
public:
	 Matrix() {
	 	matrix = new T*[mRow];
		for (int i = 0; i < mRow; ++i)
			matrix[i] = new T[mCol];
	 }
	 Matrix(int row, int col) {
		mRow = row;
		mCol = col;
		matrix = new T*[row];
		for (int i = 0; i < row; ++i)
			matrix[i] = new T[col];
	}

	Matrix(const Matrix &m) {
		mRow = m.getRow();
		mCol = m.getCol();
		this->matrix = new T*[m.getRow()];
		for (int i = 0; i < mRow; ++i)
			this->matrix[i] = new T[mCol];

		for (int i =0; i < mRow; ++i) {
			for (int j = 0; j < mCol; ++j)
				matrix[i][j] = m.matrix[i][j];
		}
	}
	~Matrix() {
		for (int i = 0; i < mRow; ++i)
			delete this->matrix[i];
		delete this->matrix;
	}

	/*T getElement(int row, int col) const {
		return this->matrix[row][col];
	}

	void setElement(int row, int col, T num) {
		this->matrix[row][col] = num;
	}*/

	int getRow() const {
		return mRow;
	}
	int getCol() const {
		return mCol;
	}

	void matrixRandomFill() {
		for (int i = 0; i < mRow; ++i) {
			for (int j = 0; j < mCol; ++j)
				this->matrix[i][j] = rand() % 20;
		}
	}

	void print() {
		for (int i = 0; i < mRow; ++i) {
			for (int j = 0; j < mCol; ++j)
				std::cout << this->matrix[i][j] << " ";
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	
	Matrix operator + (const Matrix &m) {
		Matrix res(mRow, mCol);
		for (int i = 0; i < mRow; ++i) {
			for (int j = 0; j < mCol; ++j)
				res.matrix[i][j] = this->matrix[i][j] + m.matrix[i][j];
		}
		return res;
	}

	Matrix operator - (const Matrix &m) {
		Matrix res(mRow, mCol);
		for (int i = 0; i < mRow; ++i) {
			for (int j = 0; j < mCol; ++j)
				res.matrix[i][j] = this->matrix[i][j] - m.matrix[i][j];
		}
		return res;
	}

	Matrix operator * (const Matrix &m) {
		Matrix res(mRow, mCol);
		for (int i = 0; i < mRow; ++i) {
			for (int j = 0; j < mCol; ++j)
				res.matrix[i][j] = this->matrix[i][j] * m.matrix[i][j];
		}
		return res;
	}

	Matrix &operator += (const Matrix &m) {
		for (int i = 0; i < mRow; ++i) {
			for (int j = 0; j < mCol; ++j)
				this->matrix[i][j] += m.matrix[i][j];
		}
		return *this;
	}

	Matrix &operator = (const Matrix &m) {
		for (int i = 0; i < mRow; ++i) {
			for (int j =0; j < mCol; ++j)
				this->matrix[i][j] = m.matrix[i][j];
		}
		return *this;
	}

 };

int main() {
	Matrix<int> matrix1;
	Matrix<int> matrix2;
	Matrix<int> matrix3;
	matrix1.matrixRandomFill();
	matrix2.matrixRandomFill();

	std::cout << "Matrix 1 is: \n";
	matrix1.print();
	std::cout << "Matrix 2 is : \n";
	matrix2.print();
	std::cout << "The sum of two matrixes is: \n";
	matrix3 = matrix1 + matrix2;
	matrix3.print();

	std::cout << "The difference of two matrixes is: \n";
	matrix3 = matrix1 - matrix2;
	matrix3.print();

	std::cout << "The product of two matrixes is: \n";
	matrix3 = matrix1 * matrix2;
	matrix3.print();

	std::cout << "The result after addition assignment is: \n";
	matrix1 += matrix2;
	matrix1.print();

	std::cout << "The result after assignment for matrix 1 is: \n";
	matrix3 = matrix1;
	matrix3.print();
	
	return 0;
}
