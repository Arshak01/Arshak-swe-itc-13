import sys

def hourglass(arr, row, column):
    sum1 = arr[row][column] + arr[row][column + 1] + arr[row][column + 2]
    sum3 = arr[row + 2][column] + arr[row + 2][column + 1] + arr[row + 2][column + 2]
    return (sum1 + arr[row + 1][column + 1] + sum3)

def maxSum(arr):
    max = float('-inf')
    for i in range(len(arr) - 2):
        for j in range(len(arr) - 2):
            if(max < hourglass(arr, i, j)):
                max = hourglass(arr, i, j)
    return max

arr = []
a = 0
for i in range(6):
    txt = input()
    t = txt.split()
    row = []
    for j in range(6):
        row.append(int(t[j]))
        a += 1
    arr.append(row)

print(maxSum(arr))