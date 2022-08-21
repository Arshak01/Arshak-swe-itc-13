#include <iostream>

bool primeNumberWithLoop(int num) {
	for(int i = 2; i < num / 2; i++) {
		if(num % i == 0) {
			return false;
		}
	}
	return true;
}

bool primeNumberWithRecursion(int num, int i = 2) {
	if(num % i == 0) {
		return false;
	}
	if(num / 2 < i) {
		return true;
	}
	return primeNumberWithRecursion(num, ++i);
}

int main() {
	int start, end;
	std::cout << "Please input range: ";
	std::cin >> start >> end;
	std::cout << "The prime numbers from the (" << start << " -> " << end << ") range are (with loop): ";
	for(int i = start; i <= end; i++) {
		if(primeNumberWithLoop(i)) {
			std::cout << i << ' ';
		}
	}
	std::cout << '\n';
	std::cout << "The prime numbers from the (" << start << " -> " << end << ") range are (with recursion): ";
        for(int i = start; i <= end; i++) {
                if(primeNumberWithRecursion(i)) {
			std::cout << i << ' ';
                }       
        }       
        std::cout << '\n';
	return 0;
}
