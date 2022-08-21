#include <iostream>

void ones(unsigned int n) {
	switch (n) {
			case 0: std::cout << "Zero" << " ";
			        break;
			case 1: std::cout << "One" << " ";
			        break;
			case 2: std::cout << "Two" << " ";
			        break;
			case 3: std::cout << "Three" << " ";
			        break;
			case 4: std::cout << "Four" <<" ";
			        break;
			case 5: std::cout << "Five" << " ";
			        break;
			case 6: std::cout << "Six" <<" "; 
			        break;
			case 7: std::cout << "Seven" <<" ";
			        break;
			case 8: std::cout << "Eight" << " ";
			        break;
			case 9: std::cout << "Nine" <<" ";
	}
}

void tensRight(unsigned int n) {
	switch (n) {
			case 10: std::cout << "Ten" << " ";
				 break;
			case 20: std::cout << "Twenty" << " ";
			         break;
			case 30: std::cout << "Thirty" << " ";
			         break;
			case 40: std::cout << "Fourty" <<" ";
			         break;
			case 50: std::cout << "Fifty" << " ";
			         break;
			case 60: std::cout << "Sixty" <<" "; 
			         break;
			case 70: std::cout << "Seventy" <<" ";
			         break;
			case 80: std::cout << "Eighty" << " ";
			         break;
			case 90: std::cout << "Ninety" <<" ";
	}
}

void tens(unsigned int n) {
	if (n > 10 && n < 20) {	
		switch (n) {
			case 11: std::cout << "Eleven" << " ";
				 break;
			case 12: std::cout << "Twelve" << " ";
				 break;
			case 13: std::cout << "Thirteen" << " ";
				 break;
			case 14: std::cout << "Fourteen" <<" ";
				 break;
			case 15: std::cout << "Fifteen" << " ";
				 break;
			case 16: std::cout << "Sixteen" <<" "; 
				 break;
			case 17: std::cout << "Seventeen" <<" ";
				 break;
			case 18: std::cout << "Eighteen" << " ";
				 break;
			case 19: std::cout << "Nineteen" <<" ";

		}
	} else {
		int x = n % 10;
		if (x == 0) {
			tensRight(n);
		} else if (x != 0) {
			int a = n / 10 * 10;
			tensRight(a);
			ones(x);
		}
	}
}

void hundreds(unsigned int n) {
	int x = n / 100;
	ones(x);
	std::cout << "hundred ";
	x = n - x * 100;
	if (x >= 1 && x <= 9) {
		std::cout << "and ";
		ones(x);
	} else if (x >= 10 && x <= 99) {
		std::cout << "and ";
		tens(x);
	}
}

void thousands(unsigned int n) {
	int x = n / 1000;
	ones(x);
	std::cout << "Thousand ";	
	x = n - x * 1000;
	if (x != 0) {
		hundreds(x);
	}
}

void tensThousands(unsigned int n) {
	int x = n / 1000;
	tens(x);
	std::cout << "Thousand ";
	x = n - x * 1000;
	if (x != 0) {
		hundreds(x);
	}
}

void checkNumber(unsigned int n) {
	if (n >= 0 && n <= 9) {
		ones(n);
	}
	if (n >= 10 && n <= 99) {
		tens(n);
	}
	if (n >= 100 && n <= 999) {
		hundreds(n);
	}
	if (n >= 1000 && n <= 9999) {
		thousands(n);
	}
	if (n >= 10000 && n <= 99999) {
		tensThousands(n);
	}
}

int main() {
	unsigned int n;
	std::cout << "Enter a number : ";
	std::cin >> n;
	checkNumber(n);
	
	std::cout << std::endl;
	return 0;
}
