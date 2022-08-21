
int divide(int a, int b) {
	while (a % b == 0) {
		a = a / b;
	}
	return a;
}
 
bool isUgly(int num) {
	num = divide(num, 2);
	num = divide(num, 3);
	num = divide(num, 5);

	return (num == 1) ? 1 : 0;
}

int getUglyWhile(int n) {
	int i = 1;	
	int count = 1;
 
	while (n > count) {
		i++;
		if (isUgly(i)) {
			count++;
		}
	}
	return i;
}
