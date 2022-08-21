#include <iostream>
void primeByLoop(int start, int end) {
	bool flag;
	for (int num = start; num <= end; ++num) {
		if (num == 0 || num == 1) {
			continue;
		}
		flag = true;
		for (int num1 = 2; num1 <= num / 2; ++num1) {
			if (num % num1 == 0) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			std::cout << num << " ";
		}
	}
}

bool isPrime(int num){
    bool flag=true;
    for(int i = 2; i <= num / 2; i++) {
       if(num % i == 0) {
          flag = false;
          break;
       }
    }
    return flag;
}

int primeByRecurcion(int start, int end) {
	int elem = start;
	if (start <= end) {
		if (isPrime(elem) == 1) {
			std::cout << elem << " ";
		}
		primeByRecurcion(start + 1, end);
	}
	return 0;
}	

	
int main() {
	int start;
	int end;
	std::cout << "Please input range: ";
	std::cin >> start;
	std::cin >> end;
	std::cout << "The prime numbers from the (" << start << " -> " << end << ") range are: ";

	primeByLoop(start, end);	
	std::cout << "\n" << "The prime numbers from the (" << start << " -> " << end << ") range are: ";
	primeByRecurcion(start, end);	
	std::cout << "\n";
	return 0;
}
