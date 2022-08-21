def getFibonacci(n) :
    first = 0
    second = 1
    if(n == 1) :
        print(0)
    elif(n == 2) :
        print(1)
    else :
        for i in range(2, n) :
            current = first + second
            first = second
            second = current
        print(current)

n = int(input("Please input the n: "))
getFibonacci(n)