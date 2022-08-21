
int buildingWays(int n, int i = 2, int countB = 1, int countS = 1 ) { 
	int res;
	int lastCountB = countB;
	int lastCountS = countS;
	
	countS = lastCountB + lastCountS;
	countB = lastCountS;
	res = countS + countB;
	i++; 

	if (n == 1) {
		return 4;
	}

	if(i <= n) {
		return  buildingWays(n, i, countB, countS); 
	}

	return (res * res);
}
