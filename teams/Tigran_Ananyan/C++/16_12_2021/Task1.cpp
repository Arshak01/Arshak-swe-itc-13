#include <iostream>

int add(int num1, int num2) {
    return num1 + num2;
}

int subtract(int num1, int num2) {
    return num1 - num2;
}

int **calcForMtrx(int **arr1, int **arr2, int (*opts)(int, int), int row, int coll) {
    int **answer = new int*[row];
    for(int i = 0; i < row; ++i) {
        answer[i] = new int[coll];
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < coll; ++j) {
            answer[i][j] = opts(arr1[i][j], arr2[i][j]);
        }
    }
    return answer;
}

int main() {
    int row = 3;
    int coll = 3;
    int **mtrx1 = new int*[row];
    for (int i = 0; i < row; ++i) {
       mtrx1[i] = new int[coll];
    }

    int **mtrx2 = new int*[row];
    for (int i = 0; i < row; ++i) {
       mtrx2[i] = new int[coll];
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            mtrx1[i][j] = random() % 20 + 1;
            mtrx2[i][j] = random() % 20 + 1;
        }
    }

    int **mtrx3 = calcForMtrx(mtrx1, mtrx2, add, row, coll);

    int **mtrx4 = calcForMtrx(mtrx1, mtrx2, subtract, row, coll);


    std::cout << "This is the first Matrix \n" << std::endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < coll; ++j) {
            std::cout << mtrx1[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "This is the second Matrix \n" << std::endl;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < coll; ++j) {
            std::cout << mtrx2[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Sum of matrixes \n" << std::endl;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < coll; ++j) {
            std::cout << mtrx3[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Subtract of matrixes \n" << std::endl;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < coll; ++j) {
            std::cout << mtrx4[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
