#include <iostream>
#include <vector>
#include "PowerSum.hpp"

int power(int num, unsigned int pow) {
    if (pow == 0)
        return 1;
    else if (pow % 2 == 0)
        return power(num, pow / 2) * power(num, pow / 2);
    else
        return num * power(num, pow / 2) * power(num, pow / 2);
}

int sumOfPowers(int input_num, int pow, int curr_num, int curr_sum) {
    int results = 0;
    int p = power(curr_num, pow);
    while (p + curr_sum < input_num) {
        results += sumOfPowers(input_num, pow, curr_num + 1,
                                  p + curr_sum);
        curr_num++;
        p = power(curr_num, pow);
    }
    if (p + curr_sum == input_num) {
        results++;
    }
    return results;
}
