#include <iostream>
int matrix(int **);
int matrixPrint(int **);
int mathFunc(int **, int **, int **, char);
static int row, column;

int main() {
    char ch;
    std::cout << "Enter the number of row: ";
    std::cin >> row;
    std::cout << "Enter the number of column: ";
    std::cin >> column;
    int **arr1 = new int *[row];
    for (int i = 0; i < row; ++i) {
        arr1[i] = new int[column];
    }
    matrix(arr1);
    matrixPrint(arr1);
    std::cout << std::endl;
    int **arr2 = new int *[row];
    for (int i = 0; i < row; ++i) {
        arr2[i] = new int[column];
    }
    matrix(arr2);
    matrixPrint(arr2);
    int **result = new int *[row];
    for (int i = 0; i < row; ++i) {
        result[i] = new int[column];
    }
    std::cout << "Enter math action '+' or '-': ";
    std::cin >> ch;
    mathFunc(result, arr1, arr2, ch);
    matrixPrint(result);
    return 0;
}

int matrix(int **arr) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            arr[i][j] = rand() % 20 + 1;
        }
    }
    return 0;
}

int matrixPrint(int **arr) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}

int mathFunc(int **res, int **arr1, int **arr2, char ch) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            res[i][j] = 0;
            if (ch == '+') {
                res[i][j] += arr1[i][j] + arr2[i][j];
            } else if (ch == '-'){
                res[i][j] += arr1[i][j] - arr2[i][j];
            }
        }
    }
    return 0;
}
