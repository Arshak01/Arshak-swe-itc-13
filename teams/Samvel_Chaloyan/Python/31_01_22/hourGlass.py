def hourGlass(list):
    max = float('-inf')
    count = 0

    for array in list:
        count += len(array)

    length = int(count / len(list))

    for i in range(length - 2):
        for j in range(length - 2):
            sum = list[i][j] + list[i][j+1] + list[i][j+2] + list[i+1][j+1] + list[i+2][j] + list[i+2][j+1] + list[i+2][j+2]
            if sum > max:
                max = sum
    return max

list = [[0, -4, -6, 0, -7, -6],
       [-1, -2, -6, -8, -3, -1],
       [-8, -4, -2, -8, -8, -6],
       [-3, -1, -2, -5, -7, -4],
       [-3, -5, -3, -6, -6, -6],
       [-3, -6, 0, -8, -6, -7]]

'''list = [[64, 88, 20, 2, 5, 84],
	    [10, 2, 30, 12, 74, 1],
        [53, 98, 8, 28, 4, 23],
	    [74, 67, 5, 78, 42, 1],
	    [37, 9, 61, 0, 84, 52],
	    [32, 51, 6, 16, 7, 15]]'''

max = hourGlass(list)
print("Maximum Hourglass sum: ",max)
