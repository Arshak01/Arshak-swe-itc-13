#include <iostream>
	static const char * const ones[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
	static const char * const tens[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

void numToWord(int value) {
	
	if (value < 0) {
		std::cout << "minus ";
		numToWord(-value);
	}
	else if (value >= 1000) {
		numToWord(value / 1000);
		std::cout << " thousand";
		if (value % 1000) {
			if (value % 1000 < 100) {
				std::cout << " and";
			}
			std::cout << " ";
			numToWord(value % 1000);
		}
	}
	else if (value >= 100) {
		numToWord(value / 100);
		std::cout << " hundred";
		if (value % 100) {
			std::cout << " and ";
			numToWord(value % 100);
		}
	}
	else if (value >= 20) {
		std::cout << tens[value / 10];
		if (value % 10) {
			std::cout << " ";
			numToWord(value % 10);
		}
	}
	else {
		std::cout << ones[value];
	}
}

int main() {
	int num;
	std::cout << "Enter a number: ";
	std::cin >> num;
	std::cout << "Number in words is: ";
	numToWord(num);
	std::cout << std::endl;
	return 0;
}
