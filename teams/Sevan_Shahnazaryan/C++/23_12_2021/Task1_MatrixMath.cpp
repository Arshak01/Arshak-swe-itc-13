#include <iostream>

template <typename T>
class Matrix{
private:
    T **matrix;
    int raw;
    int column;

public:
    Matrix() {
        this->raw = 3;
        this->column = 3;
        this->matrix = new T*[raw];
        for(int i = 0; i < this->raw; ++i) {
            this->matrix[i] = new T[this->column];
        }
    }

    int getRaw() const {
        return this->raw;
    }

    void setRaw(int raw) {
        this->raw = raw;
    }

    int getColumn() const {
        return this-> column;
    }

    void setColumn(int column) {
        this->column = column;
    }

    void fill(int const num, const int raw, const int column) {
        this->matrix[raw][column] = num;
    }

    Matrix math(const Matrix &mat, char sign) {
        Matrix tmp;
        for(int i = 0; i < mat.getRaw(); ++i) {
            for(int j = 0; j < mat.getColumn(); ++j) {
                switch(sign) {
                    case '+':
                        tmp.matrix[i][j] = this->matrix[i][j] + mat.matrix[i][j];
                        break;
                    case '-':
                        tmp.matrix[i][j] = this->matrix[i][j] - mat.matrix[i][j];
                        break;
                    case '*':
                        tmp.matrix[i][j] = this->matrix[i][j] * mat.matrix[i][j];
                        break;
                    }
                }
        }
        return tmp;
    }

    Matrix &assign(const Matrix &mat, std::string sign) {
        for(int i = 0; i < mat.getRaw(); ++i) {
            for(int j = 0; j < mat.getColumn(); ++j) {
                if(sign == "+="){
                    this->matrix[i][j] += mat.matrix[i][j];
                } else {
                    this->matrix[i][j] = mat.matrix[i][j];
                }
            }
        }
        return *this;
    }

    Matrix operator + (const Matrix &mat) {
        return math(mat, '+');
    }

    Matrix operator - (const Matrix &mat) {
       return math(mat, '-');
    }

    Matrix operator * (const Matrix &mat) {
        return math(mat, '*');
    }

    Matrix &operator += (const Matrix &mat) {
        return assign(mat, "+=");
    }

    Matrix &operator = (const Matrix &mat) {
        return assign(mat, "=");
    }

    void printRaw(int i) const {
        for(int j = 0; j < this->raw; ++j) {
            std::cout << this->matrix[i][j] << ' ';
        }
    }

    static void print(Matrix &mat1, std::string sign, Matrix &mat2, Matrix &mat3) {
        for(int i = 0; i < mat1.getRaw(); ++i) {
            if(i == 1) {
                mat1.printRaw(i);
                std::cout << "     " << sign << "    ";
                mat2.printRaw(i);
                std::cout << "     =    ";
                mat3.printRaw(i);
            } else{
                mat1.printRaw(i);
                std::cout << "\t\t";
                mat2.printRaw(i);
                std::cout << "\t\t";
                mat3.printRaw(i);
            }
            std::cout << std::endl;
        }
    }

    ~Matrix() {
        for(T i = 0; i < this->raw; ++i) {
            delete[] this->matrix[i];
        }
        delete[] matrix;
    }

};


void matMinus(Matrix<int> &mat1, Matrix<int> &mat2, Matrix<int> &mat3) {
    mat3 = mat1 - mat2;
    std::cout << std::endl;
    Matrix<int>::print(mat1, "-", mat2, mat3);
}

void matProduct(Matrix<int> &mat1, Matrix<int> &mat2, Matrix<int> &mat3) {
    mat3 = mat1 * mat2;
    std::cout << std::endl;
    Matrix<int>::print(mat1, "*", mat2, mat3);
}

void matPlusAssign(Matrix<int> &mat1, Matrix<int> &mat2, Matrix<int> &mat3) {
    mat3 = mat1;
    mat3 += mat2;
    std::cout << std::endl;
    Matrix<int>::print(mat1, "\b+=", mat2, mat3);
}

void matAssign(Matrix<int> &mat1, Matrix<int> &mat2, Matrix<int> &mat3) {
    mat1 = mat2;
    std::cout << std::endl;
    Matrix<int>::print(mat1, "=", mat2, mat1);
}


int main() {
    Matrix<int> mat1;
    Matrix<int> mat2;
    for(int i = 0; i < mat1.getColumn(); ++i) {
        for(int j = 0; j < mat1.getRaw(); ++j) {
            mat1.fill(5+i+j, i, j);
            mat2.fill(2+i+j, i, j);
        }
    }
    Matrix<int> mat3 = mat1 + mat2;
    Matrix<int>::print(mat1, "+", mat2, mat3);

    matMinus(mat1, mat2, mat3);

    matProduct(mat1, mat2, mat3);

    matPlusAssign(mat1, mat2, mat3);

    matAssign(mat1, mat2, mat2);
    return 0;
}
