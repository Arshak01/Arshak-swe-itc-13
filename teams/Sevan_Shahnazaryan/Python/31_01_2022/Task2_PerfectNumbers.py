from operator import truediv


def isPerfect(num):
    numCopy = num
    for i in range(1, numCopy):
        if numCopy % i == 0:
            num -= i
    if num == 0:
        return True
    else:
        return False

num = 33550336

if isPerfect(33550336):
    print(f'{num} is a Perfect number')
else:
    print(f'{num} is NOT a Perfect number')