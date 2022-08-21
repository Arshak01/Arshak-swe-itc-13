from json.encoder import INFINITY

from numpy import Infinity


def maxSum(matrix):
    maxSum = -Infinity
    for i in range(len(matrix)-2):
       for j in range(len(matrix)-2):
            sum = (matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2]) + (matrix[i + 1][j + 1]) + (matrix[i + 2][j] + matrix[i + 2][j + 1] + matrix[i + 2][j + 2])
            if(sum > maxSum):
                maxSum = sum
    return maxSum

matrix = (
        (-1,-2, -3, -4, -5, -6),
        (-7, -8, -9, -10, -11, -12),
        (-13, -14, -15, -16, -17, -18),
        (-19, -20, -21, -22, -23, -24),
        (-25, -26, -27, -28, -29, -30),
        (-31, -32, -33, -34, -35, -36))

result = maxSum(matrix)
print("The max sum of hourglass in this matrix is: ", result) 