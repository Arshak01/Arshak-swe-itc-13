#include <iostream>

int pow(int n, int m) {
	if(m == 0) {
		return 0;
	}
	if(m == 1) {
		return n;
	}
	return n * pow(n, m-1);
}

int sqrt(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	int i = 1;
	int result = 1;
	while (result <= n) {
		i++;
		result = i * i;
	}
	return i - 1;
}

void printCombs2(int n, int k, int m) {
	int limit = sqrt(n);
	int tmpNumber;
	int tmpIndex;
	for (int i = 1; i < limit; ++i) {
			tmpNumber = n;
			tmpIndex = i;
		while (tmpNumber > 0 ) {
			if (pow(tmpIndex,m) <= tmpNumber && tmpIndex != i && (pow(tmpIndex, m)+pow(i, m) == n)) {
				tmpNumber -= pow(tmpIndex, k);
				std::cout << i << "^" << m << " + " << tmpIndex << "^" << m << " = " << i*i+tmpIndex*tmpIndex+k*k  << "\t"<< std::endl;
			}
			--tmpIndex;
			if(tmpIndex == 0) {
					break;
			}
		}

	}
}

void printCombs(int n, int k) {
	std::cout << "Combinations of " << n << " is."<< std::endl;
	int limit = sqrt(n);
	int tmpNumber;
	int tmpIndex;
	for (int i = 1; i < limit; ++i) {
			tmpNumber = n;
			tmpIndex = i;
		while (tmpNumber > 0 ) {
			if (pow(tmpIndex,k) <= tmpNumber && tmpIndex != i && (pow(tmpIndex, k)+pow(i, k) == n)) {
				tmpNumber -= pow(tmpIndex, k);
				std::cout <<  i << "^" << k << " + " << tmpIndex << "^" << k << " = " << n <<  std::endl;
				printCombs2(pow(i,k), tmpIndex, k);
				printCombs2(pow(tmpIndex,k), i, k);
			}
			--tmpIndex;
			if(tmpIndex == 0) {
					break;
			}
		}
		if(tmpNumber == 0) {
			std::cout <<  i << "^" << k << " + " << tmpIndex << "^" << k << " = " << n <<  std::endl;
		}
	}
}
