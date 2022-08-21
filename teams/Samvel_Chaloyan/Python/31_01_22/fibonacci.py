print("Fibonacci sequence")
n = int(input("Enter an integer: "))



def fibo(n):
    n1, n2 = 0, 1
    count = 0

    if n <= 0:
        print("Enter a positive integer")
    elif n == 1:
        print("Fibonacci sequence for",n,":")
        print(n1)
    else:
        while count < n:
            print(n1, end=" ")
            current = n1 + n2
            n1 = n2
            n2 = current
            count += 1
        print()

def fibonacci(n):
    if n <= 1:
        return n
    else:
        return(fibonacci(n-1) + fibonacci(n-2))

def printFibo(n):
    for i in range(n):
        print(fibonacci(i), end = " ")
    print()

def main():
    printFibo(n)
    fibo(n)

main()