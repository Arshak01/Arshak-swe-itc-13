def fibRec(n):
    if n <= 1:
        return n
    else:
        return fibRec(n-1) + fibRec(n-2)

def fibLoop(n):
    count = 1
    n1 = 0
    n2 = 1
    if n <= 0:
        return n
    else:
        while count < n:
            n3 = n2 + n1
            n1 = n2
            n2 = n3
            count += 1
        else:
            return n3

index = int(input('Input index : '))
print(f'Recursion Fibonachi number of index {index} is : ',end='')
print(fibRec(index))
print(f'Loop Fibonachi number of index {index} is : ',end='')
print(fibLoop(index))
