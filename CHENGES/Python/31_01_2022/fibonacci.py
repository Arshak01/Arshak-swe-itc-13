def fibonacciRec(num):
    if num <= 1:
        return num
    else:
        return fibonacciRec(num-1) + fibonacciRec(num-2)

def fibonacciLoop(num):
    n1, n2, i = 0, 1, 1

    if num <= 1:
        return num
    else:
        while i < num:
            n = n1 + n2
            n1 = n2
            n2 = n
            i += 1
        else:
            return n

print("*** Fibonacci ***")
num = int(input("Entry number of fib : "))
print(f"Fibonacci recursion : {fibonacciRec(num)}")
print(f"Fibonacci loop : {fibonacciLoop(num)}")
