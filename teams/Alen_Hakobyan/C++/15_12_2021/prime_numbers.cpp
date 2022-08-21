#include <iostream>

void primeNumber(int fsNum, int secNum) {	
	for(int i = fsNum; i <= secNum; ++i) {
		bool flag = true;
		for(int j = 2; j <= i/2; ++j) {
			if(i % j == 0) {
				flag = false;		
			}
		}
		if(flag) {
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}

int recursiv(int num, int i = 2) {
	if(num % i == 0) {
		return 0;
	}
	else if(i * i > num) {
		return 1;
	}
	else {
		return recursiv(num, i + 1);
	}
}

void primeNumberRe(int fsNum, int secNum) {
	for(int i = fsNum; i <= secNum; ++i) {
		if(recursiv(i)) {
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}

int main() {
	int fsNum, secNum;
	std::cout << "Please input range:";
	std::cin >> fsNum >> secNum;
	std::cout << "The prime numbers from the ("<< fsNum << " -> " << secNum << ") range are: ";
	primeNumber(fsNum,secNum);
	std::cout << "This one is recursion: "; 
	primeNumberRe(fsNum,secNum);

	return 0;
}
