#include <iostream>

void printArr(int **arr, int num);

void destructor(int **arr, int num);

int **structor1(int);

int **structor2(int);

int plus(int, int);

int minus(int, int);

int **plusMinus(int **arr1, int **arr2, int num, int (*opr)(int, int));

int main() {
    int num = 3;
    int **arr1;
    int **arr2;
    int **arr3;
    arr1 = structor1(num);
    arr2 = structor2(num);

    //PLUS
    printArr(arr1, num);
    std::cout << "  +  " << std::endl;
    printArr(arr2, num);

    std::cout << "  =  " << std::endl;;

    arr3 = plusMinus(arr1, arr2, num, plus);
    printArr(arr3, num);

    std::cout << "---------------------------------------------" << std::endl;
    //MINUS
    destructor(arr3, num); //deletes arr3 to recreate for the next operation
    printArr(arr1, num);
    std::cout << "  -  " << std::endl;
    printArr(arr2, num);

    std::cout << "  =  " << std::endl;;
    arr3 = plusMinus(arr1, arr2, num, minus);
    printArr(arr3, num);

    //deleting all the arrays
    destructor(arr1, num);
    destructor(arr2, num);
    destructor(arr3, num);
    return 0;
}

int **plusMinus(int **arr1, int **arr2, int num, int (*opr)(int, int)) {
    int **arr3 = new int*[num];
    for(int i = 0; i < num; ++i) {
        arr3[i] = new int[num];
        for(int j = 0; j < num; ++j) {
            arr3[i][j] = opr(arr1[i][j], arr2[i][j]);
        }
    }
    return arr3;
}

void printArr(int **arr, int num) {
    for(int i = 0; i < num; ++i){
        for(int j = 0; j < num; ++j){
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}


//To delete arrays from heap
void destructor(int **arr, int num) {
    for(int i = 0; i < num; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = NULL;
}

int plus(int num1, int num2) {
    return num1 + num2;
}

int minus(int num1, int num2) {
    return num1 - num2;
}

int **structor1(int num) {
    int **arr1 = new int*[num];
    for(int i = 0; i < num; ++i) {
        arr1[i] = new int[num];
        for(int j = 0; j < num; ++j) {
            arr1[i][j] = i+j;
        }
    }
    return arr1;
}

int **structor2(int num) {
    int **arr2 = new int*[num];
    for(int i = 0; i < num; ++i) {
        arr2[i] = new int[num];
        for(int j = 0; j < num; ++j) {
            arr2[i][j] = i-j;
        }
    }
    return arr2;
}
