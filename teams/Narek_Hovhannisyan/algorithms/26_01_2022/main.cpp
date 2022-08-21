#include <iostream>
#include <vector>
#include <chrono>

bool isUgly(int);
int util(int, int);
int getNthUglyNumber(int);
void print(const std::vector<int> &);
int getNthUglyNumberRec(int n);
int calculateExecutingDuration(int (*callBack)(int), int n);

int main() {
    int n = 10;
    int n2 = 8;
    int n3 = 12;

    std::cout << "durations using loop" << std::endl;
    std::cout << calculateExecutingDuration(&getNthUglyNumber, n) << std::endl;
    std::cout << calculateExecutingDuration(&getNthUglyNumber, n2) << std::endl;
    std::cout << calculateExecutingDuration(&getNthUglyNumber, n3) << std::endl;
    std::cout << "ugly numbers" << std::endl;
    std::cout << getNthUglyNumber(n) << std::endl;
    std::cout << getNthUglyNumber(n2) << std::endl;
    std::cout << getNthUglyNumber(n3) << std::endl;
    std::cout << std::endl;

    int r = 10;
    int r2 = 8;
    int r3 = 12;
    std::cout << "durations using recursion" << std::endl;
    std::cout << calculateExecutingDuration(&getNthUglyNumberRec, r) << std::endl;
    std::cout << calculateExecutingDuration(&getNthUglyNumberRec, r2) << std::endl;
    std::cout << calculateExecutingDuration(&getNthUglyNumberRec, r3) << std::endl;
    std::cout << "ugly numbers" << std::endl;
    std::cout << getNthUglyNumberRec(r) << std::endl;
    std::cout << getNthUglyNumberRec(r2) << std::endl;
    std::cout << getNthUglyNumberRec(r3) << std::endl;

    return 0;
}

bool isUgly(int n) {
    n = util(n, 2);
    n = util(n, 3);
    n = util(n, 5);
    return n == 1;
}

int util(int n, int d) {
    while (n % d == 0) {
        n /= d;
    }
    return n;
}

int getNthUglyNumber(int n) {
    static std::vector<int> uglyNumbers {1};
    static int i = 1;

    while (uglyNumbers.size() < n) {
        ++i;
        if (isUgly(i)) uglyNumbers.push_back(i);
        //std::cout << "log --------------------" << std::endl;
    }
    //print(uglyNumbers);
    // you can uncomment log and print to look under the hood of the function
    return uglyNumbers[n - 1];
}

int getNthUglyNumberRec(int n) {
    static std::vector<int> uglyNumbers {1};
    static int i = 1;

    if (uglyNumbers.size() < n) {
        i++;
        if(isUgly(i)) uglyNumbers.push_back(i);
        getNthUglyNumberRec(n);
    } else {
        return uglyNumbers[n - 1];
    }
}

void print(const std::vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int calculateExecutingDuration(int (*callBack)(int), int n) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    callBack(n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}
