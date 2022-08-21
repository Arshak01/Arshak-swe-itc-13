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


int ugly(int num) {
	static std::vector<int> cache;
	int ug = 1;
	while(num > 1) {
		if(num <= cache.size() && ug == 1) {
			ug  = cache[num-1];
			break;
		} else if(num > cache.size() && cache.size() != 0 && ug == 1) {
			num -= cache.size();
			ug = cache[cache.size() - 1];
			continue;
		} else if(num == 1) {
			cache.push_back(ug);
			++ug;
			--num;
			continue;
		} else if(num == 0) {
			ug = cache[cache.size() - 1];
		}
		else if(ug == 1) {
			cache.push_back(ug);
			++ug;
			--num;
			continue;
		}
		++ug;
		if(isUgly(ug)) {
			cache.push_back(ug);
			--num;
		} else {
			continue;
		}
	}
	return ug;
}

int main() {

	using namespace std::chrono;

	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	std::cin >> num1;
	auto start = high_resolution_clock::now();
	std::cout << ugly(num1) << std::endl;
	auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Duration = " << duration.count() << " microseconds" <<std::endl;

	start = high_resolution_clock::now();
	std::cin >> num2;
	std::cout << ugly(num2) << std::endl;
	stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Duration = " << duration.count() << " microseconds" <<std::endl;

	start = high_resolution_clock::now();
	std::cin >> num3;
	std::cout << ugly(num3) << std::endl;
	stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Duration = " << duration.count() << " microseconds" <<std::endl;
	return 0;
}
