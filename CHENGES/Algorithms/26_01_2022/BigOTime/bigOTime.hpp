#include <iostream>
#include <chrono>
#include "../Ugly/whileLoop.hpp"
#include "../Ugly/recursion.hpp"
#include "../Ugly/forLoop.hpp"

using namespace std::chrono;

template <typename T>
T uglyWhile(T n) {
	std::cout << "*** Ugly While  ***" << std::endl;
	return getUglyWhile(n);
}

template <typename T>
T uglyRec(T n) {
	std::cout << "*** Ugly Recursion  ***" << std::endl;
	return getUglyRec(n);
}

template <typename T>
T uglyFor(T n) {
    std::cout << "*** Ugly For  ***" << std::endl;
    return getUglyFor(n);
}

template <typename T>
int  countTime (T n) {
	
	auto startW = high_resolution_clock::now();
	T numW = uglyWhile(n);
	std::cout << numW << std::endl;
	auto stopW = high_resolution_clock::now();
	auto durationW = duration_cast<microseconds>(stopW - startW);
	std::cout << "Duration : " << durationW.count() << std::endl;
	std::cout << std::endl;

	auto startR = high_resolution_clock::now();
	T numR = uglyRec(n);
	std::cout << numR << std::endl;
	auto stopR = high_resolution_clock::now();
	auto durationR = duration_cast<microseconds>(stopR - startR);
	std::cout << "Duration : " << durationR.count() << std::endl;
	std::cout << std::endl;

	auto startF = high_resolution_clock::now();
	T numF = uglyFor(n);
	std::cout << numR << std::endl;
	auto stopF = high_resolution_clock::now();
	auto durationF = duration_cast<microseconds>(stopF - startF);
	std::cout << "Duration : " << durationF.count() << std::endl;
	std::cout << std::endl;
	return 0;
}
