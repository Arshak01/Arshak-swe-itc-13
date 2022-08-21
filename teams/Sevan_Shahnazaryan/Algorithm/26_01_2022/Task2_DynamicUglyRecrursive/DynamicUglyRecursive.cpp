#include <iostream>
#include <vector>
#include <chrono>

bool isUgly(int num) {
	while(num != 1) {
		if(num % 2 == 0) {
			num /= 2;
		} else if(num % 3 == 0) {
			num /= 3;
		} else if(num % 5 == 0) {
			num /= 5;
		} else {
			return false;
		}
	}
	return true;
}



int ugly(int num, int ug = 1) {
	static std::vector<int> cache;
	if(ug == 1) {
		cache.push_back(ug);
		return ugly(num - 1, ug+1);
	} else if(num <= cache.size() && ug == 1) {
		return cache[num - 1];
	} else if(num > cache.size() && cache.size() != 0 && ug == 1) {
		return ugly(num - cache.size(), cache[cache.size() - 1]);
	} else if(num == 1) {
		cache.push_back(ug);
		return ug;
	} else if (num == 0) {
		return cache[cache.size() - 1];
	}
	ug += 1;
	if(isUgly(ug)) {
		cache.push_back(ug);
		return ugly(num - 1, ug);
	}
	return ugly(num, ug);
}

int main() {

	using namespace std::chrono;

	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	std::cin >> num1;
	auto start1 = high_resolution_clock::now();
	std::cout << ugly(num1) << std::endl;
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	std::cout << "Duration = " << duration1.count() << " microseconds" <<std::endl;

	std::cin >> num2;
	auto start2 = high_resolution_clock::now();
	std::cout << ugly(num2) << std::endl;
	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop2 - start2);
	std::cout << "Duration = " << duration2.count() << " microseconds" <<std::endl;

	std::cin >> num3;
	auto start3 = high_resolution_clock::now();
	std::cout << ugly(num3) << std::endl;
	auto stop3 = high_resolution_clock::now();
	auto duration3 = duration_cast<microseconds>(stop3 - start3);
	std::cout << "Duration = " << duration3.count() << " microseconds" <<std::endl;
	return 0;
}
