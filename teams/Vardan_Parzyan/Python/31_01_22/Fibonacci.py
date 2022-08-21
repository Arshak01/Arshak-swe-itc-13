# # RECURSION
def fibonacci(num):
    if num <=2:
        return 1
    else:
        return fibonacci(num-1) + fibonacci(num -2)
a = int(input("Enter your number : "))
print(fibonacci(a))

# LOOP
def fibonacciLoop(num):
    if num <=2:
        return 1
    num1 = 0
    num2 = 1
    fib = 0
    for x in range(num-1):
        fib = num1 + num2
        num1 = num2
        num2 = fib
    return fib
a = int(input("Enter your number : "))
print(fibonacciLoop(a))