#include <iostream>
#include <algorithm>
#include <vector>

int bount(int num) {
	int index = num - 1;
	static std::vector<int> mem{1, 1};
	if (num <= 2) {
		return 1;
	}
	if(num > mem.size()) {
		mem.push_back(bount(num - 1) + mem[index - 2]);
		for(auto iter = mem.begin(); iter != mem.end(); ++iter) {
			std::cout << *iter << ", ";
		}
		std::cout << std::endl;
	}
	return mem[index];


}

int main() {
	int num = 0;
	std::cout << "Enter any not numeric symbol to quit" << std::endl;
	while(std::cin >> num) {
		std::cout << bount(num + 2) * bount(num + 2) << std::endl;
	}
	return 0;
}
