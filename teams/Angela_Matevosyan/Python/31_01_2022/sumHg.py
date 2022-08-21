arr = [
        [-9,-9,-9,1,1,1],
        [0,-9,0,4,3,2],
        [-9,-9,-9,1,2,3],
        [0,0,8,6,6,0],
        [0,0,1,2,4,0]
    ]
def hourglassSum(arr):
    max_sum = -123456789
    for i in range(len(arr) - 2):
        for j in range(len(arr) - 2):
            total = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]

            if total > max_sum:
                max_sum = total
    return max_sum

print("The maximum sum of the HourGlass is", hourglassSum(arr))
