#include <vector>

int getFib (int n) {
    static std::vector<int> fib_nums{2, 3};
    static int i = 2;
    while (fib_nums.size() < n) {
        fib_nums[i] = fib_nums[i - 2] + fib_nums[i - 1];
        fib_nums.push_back(fib_nums[i]);
        ++i;
    }
    return fib_nums[n - 1];
}

int getBuildingPossibleArrangementsCount(int area) {
    static std::vector<int> cache;
    static int i = 0;
    while (cache.size() < area) {
        ++i;
        cache.push_back(getFib(i) * getFib(i));
    }
    return cache[area - 1];
}