#include <iostream>

int add(int num1, int num2) {
    return num1 + num2;
}

int subtract(int num1, int num2) {
    return num1 - num2;
}

void display2dArray(int **array, int row, int col) {
    printf("\n");
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%i ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int** change2dArray(int **arr1, int **arr2, int row, int col, int (*operation)(int, int)) {
    int **result = new int*[row];
    for(int i = 0; i < row; ++i) {
        result[i] = new int[col];
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result[i][j] = operation(arr1[i][j], arr2[i][j]);
        }
    }
    return result;
}

void freeMemoryFrom2dArray(int **array, int row) {
    for (int i = 0; i < row; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

int main() {
    int row = 3;
    int col = 3;

    int **matrix1 = new int*[row];
    for (int i = 0; i < row; ++i) {
       matrix1[i] = new int[col];
    }
    
    int **matrix2 = new int*[row];
    for (int i = 0; i < row; ++i) {
       matrix2[i] = new int[col];
    }    

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            matrix1[i][j] = random() % 90 + 10;
            matrix2[i][j] = random() % 90 + 10;
        }  
    }

    int **matrix3 = change2dArray(matrix1, matrix2, row, col, add);
    int **matrix4 = change2dArray(matrix1, matrix2, row, col, subtract);

    printf("matrix 1");
    display2dArray(matrix1, row, col);

    printf("matrix2");
    display2dArray(matrix2, row, col);

    printf("added matrix");
    display2dArray(matrix3, row, col);

    printf("subtracted matrix");
    display2dArray(matrix4, row, col);

    freeMemoryFrom2dArray(matrix1, row);
    freeMemoryFrom2dArray(matrix2, row);
    freeMemoryFrom2dArray(matrix3, row);
    freeMemoryFrom2dArray(matrix4, row);

    return 0;
}
