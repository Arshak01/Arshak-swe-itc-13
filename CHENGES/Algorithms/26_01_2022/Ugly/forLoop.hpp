#include <iostream>

int getUglyFor(int n) {

	int  uglyArr[n];

	int i2 = 0, i3 = 0, i5 = 0;
	int n2 = 2, n3 = 3, n5 = 5, n1 = 1;
 
	uglyArr[0] = 1;

	for (int i = 1; i < n; i++) {
		n1 = std::min(n2, std::min(n3, n5));
		uglyArr[i] = n1;
		
		if (n1 == n2) {
			i2 = i2 + 1;
			n2 = uglyArr[i2] * 2;
		}
		if (n1 == n3) {
			i3 = i3 + 1;
			n3 = uglyArr[i3] * 3;
		}
		if (n1 == n5) {
			i5 = i5 + 1;
			n5 = uglyArr[i5] * 5;
		}
	} 
    return n1;
}
