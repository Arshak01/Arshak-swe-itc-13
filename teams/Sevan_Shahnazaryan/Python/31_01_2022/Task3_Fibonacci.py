mem = [1, 1]

def fibRec(num):
    if num <= 2:
        return 1
    elif num > len(mem):
        mem.append(fibRec(num - 1) + mem[num - 3])
    return mem[num - 1]

def fibLoop(num):
    if num > len(mem):
        fib = mem[-1]
        prev = mem[-2]
        for i in range(len(mem), num):
            tmp = fib
            fib += prev
            prev = tmp
        return fib
    else:
        return mem[num - 1]

print("fibRec(5) = ", fibRec(8))
print("fibLoop(5) = ", fibLoop(8))