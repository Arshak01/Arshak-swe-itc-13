#include <iostream>

int convert(long value) {
	static const char *first[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "ELEVEN", 
									"TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTTEEN", "NINETEEN" };
	static const char *second[] = {"", "TEN", "TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY"};
	static const char *third[] = {"HUNDRED", "THOIUSAND", "MILLION", "BILLION" };

	if(value < 0) {
		std::cout << " ";
		convert(-value);
	} else if(value >= 1000000000) {
		convert(value / 1000000000);
		std::cout << " BILLION";
		if(value % 1000000000) {
			if(value % 1000000000 < 1000000) {
				std::cout << " AND";
			}
			std::cout << " ";
			convert(value % 1000000000);
		}
	} else if(value >= 1000000) {
		convert(value / 1000000);
		std::cout << " MILLION";
		if(value % 1000000) {
			if(value % 1000000 < 1000) {
				std::cout << " AND";
			}
			std::cout << " ";
			convert(value % 1000000);
		}
	} else if(value >= 1000) {
		convert(value / 1000);
		std::cout << " THOUSAND";
		if(value % 1000) {
			if(value % 1000 < 100) {
				std::cout << " AND";
			}
			std::cout << " " ;
			convert(value % 1000);
		}
	} else if(value >= 100) {
		convert(value / 100);
		std::cout << " HUNDRED";
		if(value % 100) {
			std::cout << " AND ";
			convert(value % 100);
		}
	} else if(value >= 20) {
		std::cout << second[value / 10];
		if(value % 10) {
			std::cout << " ";
			convert(value % 10);
		}
	} else {
		std::cout << first[value];
	}
    
	return 0;
}

int main() {
	long n = 0;
	std::cout << "Entry number : " ;
	std::cin >> n;
	convert(n);
	std::cout<< std::endl;
	
	return 0; 
}
