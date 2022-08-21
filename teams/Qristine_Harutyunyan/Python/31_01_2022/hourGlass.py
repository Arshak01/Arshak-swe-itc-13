def hourGlass(matrix):
	maxSum = float('-inf')
	for i in range(len(matrix) - 2):
		for j in range(len(matrix) - 2):
			sum = (matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2]) + matrix[i + 1][j + 1] + matrix[i + 2][j] + matrix[i + 2][j + 1] + matrix[i + 2][j + 2]
			if sum > maxSum:
				maxSum = sum
	return maxSum


matrix = [[-9, -9, -9, 1, 1, 1],
          [0, -9, 0, 4, 3, 2, 1],
		  [-9, -9, -9, 1, 2, 3],
		  [0, 0, 8, 6, 6, 0],
		  [0, 0, 0, -2, 0, 0],
		  [0, 0, 1, 2, 4, 0]]

print("MaxSum is ", hourGlass(matrix))		  					
