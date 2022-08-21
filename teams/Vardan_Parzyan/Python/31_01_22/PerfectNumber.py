def perfectionCheck(num):
    sum = 1
    i = 2
    while i * i <= n:
        if num % i == 0:
            sum = sum + i + n/i
        i += 1
    if sum == n and n > 1:
        return True
    else:
        return False

print("")
n = int(input("Enter your number "))
if perfectionCheck(n):
        print(True)
else:
    print(False)