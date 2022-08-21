#include <iostream>


template <class T>
class Matrix {
private:
    int row = 3;
    int column = 3;
    T** matrix;

public:
    Matrix() {
        matrix = new T*[row];
        for (int i = 0; i < this->row; ++i) {
            matrix[i] = new T[this->column];
        }
    }

    Matrix(int r, int c) {
        this->row = r;
        this->column = c;
        matrix = new T*[r];
        for (int i = 0; i < r; ++i) {
            matrix[i] = new T[c];
        }
    }

    Matrix(const Matrix& m) {
        this->column = m.getColumn();
        this->row = m.getColumn();

        this->matrix = new T*[m.getRow()];
        for (int i = 0; i < this->row; ++i) {
            this->matrix[i] = new T[this->column];
        }
    }

    ~Matrix() {
        clearMatrixMemory();
    }

    int getRow() const {
        return this->row;
    }

    int getColumn() const {
        return this->column;
    }

    void autoFill() {
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                this->matrix[i][j] = std::rand() % 10;
            }
        }
    }

    void print() {
        for (int i = 0; i < this->row; ++i) {
            std::cout << std::endl;
            for (int j = 0; j < this->column; ++j) {
                std::cout << this->matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void clearMatrixMemory() {
        for (int i = 0; i < this->row; ++i) {
            delete[] this->matrix[i];
        }
        delete[] this->matrix;
    }

    Matrix operator + (const Matrix& m) {
        Matrix result(this->row, this->column);
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                result.matrix[i][j] = this->matrix[i][j] + m.matrix[i][j];
            }
        }
        return result;
    }

    Matrix& operator = (const Matrix& m) {
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                this->matrix[i][j] = m.matrix[i][j];
            }
        }
        return *this;
    }

    Matrix operator - (const Matrix& m) {
        Matrix result(this->row, this->column);
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                result.matrix[i][j] = this->matrix[i][j] - m.matrix[i][j];
            }
        }
        return result;
    }

    Matrix operator * (const Matrix& m) {
        Matrix result(this->row, this->column);
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                result.matrix[i][j] = this->matrix[i][j] * m.matrix[i][j];
            }
        }
        return result;
    }
    
    Matrix& operator += (const Matrix& m) {
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                this->matrix[i][j] += m.matrix[i][j];
            }
        }
        return *this;
    }

};

int main() {
    Matrix<int> matrix1(3, 3);
    Matrix<int> matrix2(3, 3);
    Matrix<int> matrix3(5, 5);

    matrix1.autoFill();
    matrix2.autoFill();

    std::cout << "Matrix 1" << std::endl;
    matrix1.print();

    std::cout << "Matrix 2" << std::endl;
    matrix2.print();

    Matrix<int> added = matrix1 + matrix2;
    std::cout << " + operator" << std::endl;
    added.print();

    Matrix<int> equivalent = matrix1;
    std::cout << " = operator with matrix 1" << std::endl;
    equivalent.print();

    Matrix<int> sub = matrix1 - matrix2;
    std::cout << " - operator" << std::endl;
    sub.print();

    Matrix<int> multiple = matrix1 * matrix2;
    std::cout << " * operator" << std::endl;
    multiple.print();

    matrix1 += matrix2;
    std::cout << " += operator, matrix 1 after += with matrix 2" << std::endl;
    matrix1.print();
    
    return 0;
}
