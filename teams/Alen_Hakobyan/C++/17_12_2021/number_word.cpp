#include <iostream>

void count(int number);

int main() {
	
	int number = 0;
	std::cout << "Write a number(0-99): ";
	std::cin >> number;
	count(number);
	
	return 0;
}

void count(int number) {
	static const char *unit[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	static const char *decimal[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	static const char *dozen[] = {"ten","twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

	if(number == 0) {
		std::cout << "Zero" << std::endl;
	}
	else if(number < 10) {
		for(int i = number; i <=9; ++i){
			std::cout << unit[i] << std::endl;
			break;
		}
	}
	else if(number == 10) {
		std::cout << dozen[0] << std::endl;
	}
	else if(10 < number && number < 20) {
		for(int j = number; ;++j) {
			std::cout << decimal[j % 10-1] << std::endl;
			break;
		}
	}
	else if(19 < number && number < 100) {
		for(int x = number; ; ++x) {
			std::cout << dozen[x / 10 - 1] << " " << unit[number % 10] << std::endl;
			break;
		}
	}
}
