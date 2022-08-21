def hourglass(matrix):
    hourglass_max_sum = -float("inf")
    print(hourglass_max_sum)
    if len(matrix) < 3 or len(matrix[0]) < 3:
        return 0
    for i in range(0, len(matrix) - 2):
        for j in range(0, len(matrix[i]) - 2):
            tmp_sum = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] + matrix[i + 1][j + 1] + matrix[i + 2][j] + \
                      matrix[i + 2][j + 1] + matrix[i + 2][j + 2]
            if hourglass_max_sum < tmp_sum:
                hourglass_max_sum = tmp_sum
    return hourglass_max_sum


mx = [
    [1, 1, 1, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [1, 1, 1, 0, 0, 0],
    [0, 0, 2, 4, 4, 0],
    [0, 0, 0, 2, 0, 0],
    [0, 0, 1, 2, 4, 0]
]
print(hourglass(mx))

mx2 = [
    [-5, -1, -2, -7, -4, 0],
    [-4, -8, 0, -1, -3, 0],
    [-4, -8, 0, 1, -3, 0],
    [-2, -1, -5, 0, -9, 0],
    [-2, -6, -4, -5, -1, 0],
    [-3, -3, -3, -5, -7, 0]
]
print(hourglass(mx2))
