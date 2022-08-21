#include "buildings.cpp"

int main() {
	int N = 10;
	int cache[N-1];
	int size = sizeof(cache) / sizeof(cache[0]); 
	std::cout << countWays(cache, N, size)<< std::endl;
	std::cout << countWays(cache, 7, size)<< std::endl;
	std::cout << countWays(cache, 15, size)<< std::endl;
	std::cout << countWays(cache, 13, size)<< std::endl;
	
	return 0;
}
