# My implementation of Merge sort

**My program consists of 4 files:**

	* CmakeLists.txt(Minimum required version 3.10)
	* Main.cpp (main function is here)
	* MergeSort.cpp, MergeSort.hpp (SelSort namespace)

**I made the following functions for ShellSort**

	* print(arr, size) *prints the array*
	* randomGen(size) *Generetes an array with give size*
	* sort(arr, size) *Devides the array and calls merge function*
	* merge(int arr, int left, int middle, int right, int size) *Sorts and merges 2 arrays*
	* copy(int arr1, int arr2, int i, int right) *copies one array into another*
	* temper(int arr1, int arr2, int i1, int i2) *fills temp array with sorted elements*

***To use the program***

Write the following commads in terminal from the current directery

	◦mkdir build
	◦cd build
	◦cmake .. .
	◦make
	◦./MergeSort

Hope you enjoy my programs (^_^)

© Sevan Shahnazaryan. Future(hopefully) Developer in Instigate Mobile.
2022. All rights reserved.
