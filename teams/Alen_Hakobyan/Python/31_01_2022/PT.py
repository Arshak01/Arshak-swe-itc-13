def pascalT(n):
    for i in range(n + 1):
        for j in range(n - i):
            print(" ",end='')
        m = 1
        for f in range(1,i+1):
            print(" ",m,sep='',end='')
            m = m * (i - f) // f
        print()

n = int(input('Input number to see Pascal\'s Triangle : '))
pascalT(n)
