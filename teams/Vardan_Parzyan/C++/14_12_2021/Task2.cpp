#include <iostream>

void ArrayDesscending(int arr[]);

void ArrayAscending(int arr[]);

void ArrayRevert(int arr[]);

void ArrayPrint(int arr[]);


int main() {
    int array[10] = {5, 10, 4, 6, 9, 2, 7, 3, 8, 1};

    std::cout << "Initial array : ";
    ArrayPrint(array);
    std::cout << std::endl;

    std::cout << "Reversed array :";
    ArrayRevert(array);
    ArrayPrint(array);
    std::cout << std::endl;

    std::cout << "Array after ascending : ";
    ArrayAscending(array);
    ArrayPrint(array);
    std::cout << std::endl;

    std::cout << "Array after descending : ";
    ArrayDesscending(array);
    ArrayPrint(array);
    std::cout << std::endl;

    return 0;
}

void ArrayDesscending(int arr[]) {
    bool isReady = false;
    while (!isReady) {
        isReady = true;
        for (int i = 0; i < 9; i++) {
            if (arr[i] < arr[i + 1]) {
                int tmp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = tmp;
                isReady = false;
            }
        }
    }

}

void ArrayAscending(int arr[]) {
    for (int i = 0; i < 10; i++) {
        int pos = i;
        int min = arr[i];
        for (int j = i + 1; j < 10; j++) {
            if (arr[j] < min) {
                pos = j;
                min = arr[j];
            }
        }
        arr[pos] = arr[i];
        arr[i] = min;
    }

}

void ArrayRevert(int arr[]) {
    int temp, length = 10;
    int i = 0;
    int j = length - 1;
    while (i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

void ArrayPrint(int arr[]) {
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
