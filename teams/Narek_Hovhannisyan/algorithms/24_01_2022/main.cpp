#include <iostream>
#include <vector>
#include <cmath>

void print(std::vector<std::vector<int>> &, int, int);

int powSum(int n, const int k, int i, std::vector<std::vector<int>> &combs, int vecIndex = 0) {
    static int src = n;
    if (i == 1) {
        combs.resize(pow(n, 1.0 / k));
    }

    const int v = n - pow(i, k);
    
    if (v < 0) vecIndex++;
    std::cout << "v = " << v << std::endl;
    std::cout << "vecIndex = " << vecIndex << std::endl;
    std::cout << std::endl;
    if (v >= 0) combs[vecIndex].push_back(i);
    
    if (v == 0) {
        // ++vecIndex;
        return 1;
    } else if (v < 0) {
        // combs[i].clear();
        // ++vecIndex;
        return 0;
    }

    return powSum(v, k, i + 1, combs, vecIndex) + powSum(n, k, i + 1, combs, vecIndex);
}

int main() {
    std::vector<std::vector<int>> v;
    int n = 25;
    int k = 2;
    int count = powSum(n, k, 1, v);
    print(v, n, k);
    std::cout << "count = " << count << std::endl;

    return 0;
}

void print(std::vector<std::vector<int>> &v, int N, int k) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << N << " = ";
        for (int j = 0; j < v[i].size(); j++) {
            std::cout << v[i][j] << "^" << k;
            if (j != v[i].size() - 1) std::cout << " + ";
        }
        std::cout << std::endl;
    }
}

