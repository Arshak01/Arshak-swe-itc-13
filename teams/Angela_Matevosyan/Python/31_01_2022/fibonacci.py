n = int(input("Enter the number: "))
def fibonacciRec(n):
    if n <= 0:
        print("Incorrect input")
    elif n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        return fibonacciRec(n-1) + fibonacciRec(n-2)
print("Is called function with recursion.")
print("The nth Fibonacci number is", fibonacciRec(n))

def fibonacciLoop(n):
    if n <= 0:
        return "Incorrect input"
    data = [0, 1]
    if n > 2:
        for i in range(2, n):
            data.append(data[i-1] + data[i-2])
    return data[n-1]
print("Is called function with loop.")
print("The nth Fibonacci number is", fibonacciLoop(n))
