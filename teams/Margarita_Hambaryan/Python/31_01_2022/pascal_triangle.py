def pascal_triangle(n):
    my_list = [[] for i in range(n)]
    for i in range(n):
        for j in range(i + 1):
            if (j < i):
                if (j == 0):
                    my_list[i].append(1)
                else:
                    my_list[i].append(my_list[i - 1][j] + my_list[i - 1][j - 1])
            elif(j == i):
                my_list[i].append(1)
    
    for elem in my_list:
        print(*elem)

# Driver code  
# pascal_triangle(5)