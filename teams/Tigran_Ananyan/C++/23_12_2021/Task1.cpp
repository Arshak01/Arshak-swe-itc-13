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
        this->matrix = new T *[r];
        for (int i = 0; i < r; ++i) {
            this->matrix[i] = new T [c];
        }
    }

    ~Matrix() {
        deleteMatrix();
    }

    int getRow() const {
        return this->row;
    }

    int getColumn() const {
        return this->column;
    }

    void randomFill() {
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                this->matrix[i][j] = std::rand() % 50;
            }
        }
    }

    void printRow(int i) {
        for(int j = 0; j < this->row; ++j) {
            std::cout << this->matrix[i][j] << ' ';
        }
    }

    static void print(Matrix &matrix1, std::string oper, Matrix &matrix2, Matrix &matrix3) {
        for(int i = 0; i < matrix1.getRow(); ++i) {
            if(i == 1) {
                matrix1.printRow(i);
                std::cout << "       " << oper << "       ";
                matrix2.printRow(i);
                std::cout << "      =         ";
                matrix3.printRow(i);
            } else{
                matrix1.printRow(i);
                std::cout << "\t\t";
                matrix2.printRow(i);
                std::cout << "\t\t";
                matrix3.printRow(i);
            }
            std::cout << std::endl;
        }
    }

    void deleteMatrix() {
        for (int i = 0; i < this->row; ++i) {
            delete[] this->matrix[i];
        }
        delete[] this->matrix;
    }

    Matrix operator + (const Matrix &m) {
        Matrix result(this->row, this->column);
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                result.matrix[i][j] = this->matrix[i][j] + m.matrix[i][j];
            }
        }
        return result;
    }

    Matrix& operator = (const Matrix &m) {
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                this->matrix[i][j] = m.matrix[i][j];
            }
        }
        return *this;
    }

    Matrix operator - (const Matrix &m) {
        Matrix result(this->row, this->column);
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                result.matrix[i][j] = this->matrix[i][j] - m.matrix[i][j];
            }
        }
        return result;
    }

    Matrix operator * (const Matrix &m) {
        Matrix result(this->row, this->column);
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                result.matrix[i][j] = this->matrix[i][j] * m.matrix[i][j];
            }
        }
        return result;
    }

    Matrix& operator += (const Matrix &m) {
        Matrix result(this->row, this->column);
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

    matrix1.randomFill();
    matrix2.randomFill();

    std::cout << "Matrix1                 Matrix2                 Matrix3\n" << std::endl;
    Matrix<int> matrix3 = matrix1 + matrix2;
    Matrix<int>::print(matrix1, "+", matrix2, matrix3);
    std::cout << "\n";

    matrix3 = matrix1 - matrix2;
    Matrix<int>::print(matrix1, "-", matrix2, matrix3);
    std::cout << "\n";

    matrix3 = matrix1 * matrix2;
    Matrix<int>::print(matrix1, "*", matrix2, matrix3);
    std::cout << "\n";

    matrix3 = matrix1;
    matrix3 += matrix2;
    Matrix<int>::print(matrix1, "\b+=", matrix2, matrix3);
    std::cout << "\n";

    matrix1 = matrix2;
    Matrix<int>::print(matrix1, "= ", matrix2, matrix2);


    return 0;
}
