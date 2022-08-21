#include <iostream>

int countWays(int number, int countB, int countS, int count);

int main() {
	std::cout << "Input number to see count possible ways to construct building: ";
	int countB = 1;
	int countS = 1;
	int count = 2;
	int number;
	std::cin >> number;
	std::cout << countWays(number,countB,countS,count) << " possible ways." << std::endl;
	return 0;
}

int countWays(int number, int countB, int countS, int count) {
	int prevS, prevB, result;
	prevB = countB;
	prevS = countS;
	countB = prevS;
	countS = prevS + prevB;
	result = countS + countB;
	++count;
	if(number == 1) {
		return 4;
	}
	if(number >= count) {
		return countWays(number, countB, countS, count);
	}
	return result * result;
}
