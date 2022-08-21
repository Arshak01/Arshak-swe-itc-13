import math

def hourglassSum(arr):
    result = -math.inf
    for i in range(4):
        for j in range(4):
            sum_ = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] + \
                 arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2]
            result = max(result, sum_)
    return result


n = 6
arr = [[int(x) for x in input().split()] for _ in range(n)]

def main():
    print(hourglassSum(arr))

if __name__ == '__main__':
    main()
    