#include <iostream>
#include <chrono>
#include "../Ternary/ternary.hpp"
#include "../Interpolation/interpolation.hpp"
#include "../Exponental/exponental.hpp"

using namespace std::chrono;

template <typename T>
void ternarySearch(T* arr, int l, int r, T key) {
	std::cout << "*** Ternary search  ***" << std::endl;
	int index = ternary(arr, l, r, key);
	if(index == -1) {
		std::cout << "There is not element" << std::endl;
	} else {
		std::cout << "Index of key : " << index << std::endl;
	}
}

template <typename T>
void interpolationSearch(T* arr, int l, int r, T key) {
	std::cout << "*** Interpolation search  ***" << std::endl;
	int index = interpolation(arr, l, r, key);
	if(index == -1) {
		std::cout << "There is not element" << std::endl;	
	} else {
		std::cout << "Index of key : " << index << std::endl;
	}
}

template <typename T>
void exponentalSearch(T* arr, int r, T key) {
	std::cout << "*** Exponental search  ***" << std::endl;
	int index = exponental(arr, r, key);
	if(index == -1) {
		std::cout << "There is not element" << std::endl;	
	} else {
	std::cout << "Index of key : " << index << std::endl;
	}
}

template <typename T>
int  countTime (T* arr,int l, int n, T key) {
	
	auto startT = high_resolution_clock::now();
	ternarySearch(arr, l, n, key);
	auto stopT = high_resolution_clock::now();
	auto durationT = duration_cast<microseconds>(stopT - startT);
	std::cout << "Duration : " << durationT.count() << std::endl;
	std::cout << std::endl;

	auto startE = high_resolution_clock::now();
	exponentalSearch(arr, n, key);
	auto stopE = high_resolution_clock::now();
	auto durationE = duration_cast<microseconds>(stopE - startE);
	std::cout << "Duration : " << durationE.count() << std::endl;
	std::cout << std::endl;
	
	auto startI = high_resolution_clock::now();
	interpolationSearch(arr, l, n, key);
	auto stopI = high_resolution_clock::now();
	auto durationI = duration_cast<microseconds>(stopI - startI);
	std::cout << "Duration : " << durationI.count() << std::endl;
	std::cout << std::endl;

	return 0;
}
