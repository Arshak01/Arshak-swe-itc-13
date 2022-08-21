#ifndef QUICK_SHELL_SORT
#define QUICK_SHELL_SORT

void shellSort(int *arr, int size);
void quickSort(int *arr, int size);
void print(int* arr, int size);


void swap(int* a, int* b);
int partition(int* arr, int lowInd, int highInd);
void quickSort(int* arr, int low, int high);

#endif

