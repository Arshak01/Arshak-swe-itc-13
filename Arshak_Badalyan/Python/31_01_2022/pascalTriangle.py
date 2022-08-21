
def pascal(num):
    for i in range(num+1):
        for j in range(num-i):
            print(" ",end=" ")
        p = 1
        for k in range(1, i+1):
            print(" ", p, sep=" ", end=" ")
            p = p*(i-k)//k
        print()

num=int(input("Entry number : "))
pascal(num)
