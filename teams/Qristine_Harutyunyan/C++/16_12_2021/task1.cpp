#include <iostream>
int diff(int a, int b) {
    return a - b;
}
int sum(int a, int b) {
    return a + b;
}
int** actionWithinArray(int** arr1, int** arr2, int row, int col, int(* check)(int, int)) {
    int** res = new int*[row];
    for (int i = 0; i <= row; ++i) {
        res[i] = new int[col];
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            res[i][j] = check(arr1[i][j], arr2[i][j]);
        }
    }
    return res;
}

void showMatric(int** arr, int rows, int coloms){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < coloms; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int rows = 3;
    int coloms = 3;
    int** first = new int*[rows];
    for (int i = 0; i <= coloms; ++i) {
        first[i] = new int[coloms];
    }
    int** second = new int*[rows];
    for (int i = 0; i <= coloms; ++i) {
        second[i] = new int[coloms];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < coloms; ++j) {
            first[i][j] = i + j ;
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < coloms; ++j) {
            second[i][j] = (i + j) + 5;
        }
    }

    std::cout << "first 2dArray is ` " << std::endl;
    showMatric(first, rows, coloms);

    std::cout << "second 2dArray is ` " << std::endl;
    showMatric(second, rows, coloms);

    int **diffMat = actionWithinArray(first, second, rows, coloms, diff);
    std::cout << "Difference is`" << std::endl;
    showMatric(diffMat, rows, coloms);

    int **sumMat = actionWithinArray(first, second, rows, coloms, sum);
    std::cout << "Sum is" << std::endl;
    showMatric(sumMat, rows, coloms);
}
