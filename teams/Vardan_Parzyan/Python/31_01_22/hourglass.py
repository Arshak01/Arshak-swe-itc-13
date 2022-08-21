def MaxSum(list):
	maxSum = -99999
	for i in range(0, 4):
		for j in range(0, 4):
			SUM = (list[i][j] + list[i][j + 1] + list[i][j + 2]) + (list[i + 1][j + 1]) + (list[i + 2][j] + list[i + 2][j + 1] + list[i + 2][j + 2])
			if(SUM > maxSum):
				maxSum = SUM
	return maxSum

list = [[5, 1, 2, 7, 4, 0],
	[4, 8, 0, 1, 3, 0],
        [4, 8, 0, 1, 3, 0],
	[2, 1, 5, 0, 9, 0],        ##  5 0 9
	[2, 6, 4, 5, 1, 0],        ##  - 5 -
	[3, 3, 3, 5, 7, 0]]        ##  3 5 7
result = MaxSum(list)
print(f"The bigest 'hourglass' sum is : {result}")

