import numpy as np
import math

def printMatrix(matrix):
    print()
    print("*** Matrix ***")
    for i in range(0, len(matrix)):
        for j in range(0, len(matrix)):
            print(matrix[i][j], sep="", end=" ")
        print()
    print()

def hourGlass(matrix):
    if len(matrix) < 3:
        return "Entry number up to two !"

    maxSum = -math.inf
    for i in range(len(matrix)-2):
        for j in range(len(matrix)-2):
            sum=(matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2]) + \
                (matrix[i + 1][j + 1]) + \
                (matrix[i + 2][j] + matrix[i + 2][j + 1] + matrix[i + 2][j + 2])
            if maxSum < sum:
                maxSum = sum
    return maxSum

n = int(input("Entry size of matrix : "))
matrix = np.random.randint(-5,15, size=(n, n))
printMatrix(matrix)

result = hourGlass(matrix)
print(f'sum is : {result}')
