namespace MergeSort{
	void sort(int *arr, int left, int right, int size);

	void merge(int *arr, int left, int middle, int right, int size);

	void copy(int *arr1, int *arr2, int i, int right);

	void temper(int *arr1, int *arr2, int *i1, int *i2);

	int* randomGen(int size);

	void print(int *arr, int size);
}
