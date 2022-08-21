def pascalTriangle (num):
    row = [1]
    y = [0]
    for x in range(num):
        print(row)
        row = [l + r for l,r in zip(row + y, y + row )]
    return num >=1
pascalTriangle(5)
