def fibonacci(n):
    a = 0
    b = 1
    if n == 0:
        return a
    for _ in range(0, n - 1):
        b += a
        a = b - a
    return b


# fibonacci numbers start form 0 index
# https://en.wikipedia.org/wiki/Fibonacci_number
# F0 F1 F2 F3 F4 F5 F6 F7 F8 F8 F10
# 0  1  1  2  3  5  8  13 21 35 54
print(fibonacci(0), end=" ")
print(fibonacci(1), end=" ")
print(fibonacci(2), end=" ")
print(fibonacci(3), end=" ")
print(fibonacci(4), end=" ")
print(fibonacci(5), end=" ")
print(fibonacci(6))


def fibonacci_rec(n):
    if n < 2:
        return n
    return fibonacci_rec(n - 2) + fibonacci_rec(n - 1)


print("fibonacci_rec")
print(fibonacci_rec(0), end=" ")
print(fibonacci_rec(1), end=" ")
print(fibonacci_rec(2), end=" ")
print(fibonacci_rec(3), end=" ")
print(fibonacci_rec(4), end=" ")
print(fibonacci_rec(5), end=" ")
print(fibonacci_rec(6))
