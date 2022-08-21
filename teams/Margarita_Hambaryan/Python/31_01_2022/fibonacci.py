def fib(n):
    if n < 0:
        return 'n must be positive'
    if n <= 1:
        return n
    else:
        return (fib(n - 1) + fib(n - 2))

def fib_loop(n):
    f1 = 0
    f2 = 1
    if n < 0:
        return 'n must be positive'
    elif n <= 1:
        return n
    else:
        for i in range(2, n):
            temp = f2 + f1
            f1 = f2
            f2 = temp
    
    return f1 + f2

# Driver code
# print(fib(6))
# print(fib_loop(6))