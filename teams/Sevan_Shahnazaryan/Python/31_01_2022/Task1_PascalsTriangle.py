row = [1]

def triangle(num):
    if num <= 0:
        return
    if num % 2 == 1:
        print(' ' * ((num*2) // 2), end = ' ')
        print(*row)
    else:
        print(' ' * ((num*2) // 2), end = ' ')
        print(*row[:(len(row) ) // 2], *row[(len(row)) // 2:] )
    for i in range(len(row) - 1):
        row[i] = row[i] + row[i + 1]
    row.insert(0,1)
    triangle(num-1)

triangle(6)