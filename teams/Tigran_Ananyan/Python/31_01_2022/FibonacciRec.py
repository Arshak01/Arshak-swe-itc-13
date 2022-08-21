from ctypes import wstring_at


def getFibonacci(n) :
    if(n == 1) :
        return 0
    elif(n == 2) :
        return 1
    else :
        return getFibonacci(n - 1) + getFibonacci(n - 2)

n = int(input("Please input the n: "))
print(getFibonacci(n))