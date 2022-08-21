#include <iostream>
#include <chrono>
using namespace std::chrono;

int maxDivide(int a, int b) {
	while(a % b == 0) {
		a = a / b;
	}
	return a;
}

int isUgly(int num) {
	num = maxDivide(num,2);
	num = maxDivide(num,3);
	num = maxDivide(num,5);
	if (num == 1)
	    return 1;
	return 0;
}

int getUglyNum(int num) {
	int i = 1;
	int count = 1;
	while(num > count) {
		i++;
		if(isUgly(i)) {
			count++;
		}
	}
	return i;
}

int main() {
    auto start = high_resolution_clock::now();
    std::cout << "Ugly number is : " << getUglyNum(25) << std::endl;
	auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Complate in : " << duration.count() << std::endl;
	return 0;
}
