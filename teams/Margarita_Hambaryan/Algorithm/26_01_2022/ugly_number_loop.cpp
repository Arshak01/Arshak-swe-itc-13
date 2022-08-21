#include "ugly_number_loop.hpp"
#include <iostream>

int getUglyByLoop(int n){
	int ugly[n];
	int i2 = 0;
	int i3 = 0;
	int i5 = 0;
	int next_multiple_of_2 = 2;
	int next_multiple_of_3 = 3;
	int next_multiple_of_5 = 5;
	int next_ugly_number = 1;

	ugly[0] = 1;
	for (int i = 1; i <= n; ++i) {
		next_ugly_number = std::min(
			next_multiple_of_2,
			std::min(next_multiple_of_3, next_multiple_of_5));
		ugly[i] = next_ugly_number;
		if (next_ugly_number == next_multiple_of_2) {
			i2 = i2 + 1;
			next_multiple_of_2 = ugly[i2] * 2;
		}
		if (next_ugly_number == next_multiple_of_3) {
			i3 = i3 + 1;
			next_multiple_of_3 = ugly[i3] * 3;
		}
		if (next_ugly_number == next_multiple_of_5) {
			i5 = i5 + 1;
			next_multiple_of_5 = ugly[i5] * 5;
		}
	}

	return next_ugly_number;
}
