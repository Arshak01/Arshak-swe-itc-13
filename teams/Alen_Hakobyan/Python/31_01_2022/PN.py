def perfNumber(n):
    m = 0
    for i in range(1,n):
        if(n % i == 0):
            m += i
    if m == index:
        print(f'{index} is perfect number.')
    else:
        print(f'{index} is not perfect number')

index = int(input('Input number to check is perfect or not '))
perfNumber(index)
