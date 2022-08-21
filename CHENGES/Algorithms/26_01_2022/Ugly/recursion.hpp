
int divideRec(int a, int b) {
	while(a % b == 0) {
		a /= b;
	}
	return a;
}

bool isUglyRec(int num) {
	num = divideRec(num, 2);
	num = divideRec(num, 3);
	num = divideRec(num, 5);

	return num == 1;
}

int getUglyRec(int i) {
	static int num = 1;
	static int count = 1;
		++num;
		if(isUglyRec(num)) {
			++count;
		}
		if(count == i) {
			return num;
		}
	return getUglyRec(i);
}
