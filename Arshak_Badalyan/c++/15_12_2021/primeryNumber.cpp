#include <iostream>  

int primeLoop(int low, int high) {  
	int i;
		bool isPrime = true;
		while(low < high) {
			isPrime = true;
			if(low == 0 || low == 1) {
				isPrime = false;
			} else {
				for(i = 2; i <= low / 2; ++i) {
						if(low % i == 0) {
								isPrime = false;
								break;
						}
				}
			}
			if(isPrime) {
				std::cout << low << " " ;
			}
			++low;
		}
		std::cout << std::endl;
		
		return 0;
}

int recursion(int num, int i = 2) {
	if(num % i == 0) {
		return 0;
	} else if(i * i > num) {
		return 1;
	} else {
		return recursion(num, i + 1);
	}
}

void primeRecursion(int start, int end) {
	for(int i = start; i <= end; ++i) {
		if(recursion(i)) {
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}

int main() {
	int start;
	int end;
	std::cout << "Input first  number : " << std::endl;
	std::cin >> start;
	std::cout << "Input second  number : " << std::endl;
	std::cin >> end;
	std::cout << "\n**** FIND PRIME NUMBERS WITH LOOP ****" << std::endl;
	primeLoop(start, end);	
	std::cout << "\n**** FIND PRIME NUMBERS WITH RECURSIA ****" << std::endl;
	primeRecursion(start, end);

	return 0;
}
