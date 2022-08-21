n = int(input("Enter an integer: "))

def perfectNumber(n):
    sum = 0
    for i in range(1,n):
        if n % i == 0:
            sum += i
    if sum == n:
        print("It's a Perfect number!")
    else:
        print("It's not a Perfect number!")

perfectNumber(n)