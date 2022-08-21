def maxSum(matrix):
    maxSum = float('-inf')
    for i in range(len(matrix)-2):
        for j in range(len(matrix)-2):
            sum = (matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2]) + (matrix[i + 1][j + 1]) + (matrix[i + 2][j] + matrix[i + 2][j + 1] + matrix[i + 2][j + 2])
            if(sum > maxSum):
                maxSum = sum
    return maxSum

matrix = ((8, 9, 3, 5, 7, 0),
        (1, 9, 6, 9, 1, 4),
        (6, 8, 1, 1, 3, 3),
        (1, 1, 5, 4, 1, 2),
        (3, 6, 4, 2, 9, 5),
        (2, 7, 9, 8, 7, 4))

result = maxSum(matrix)
print(f'Max sum is : {result}')