def is_perfect_number(n):
    my_list = []
    for i in range(1, n):
        if n % i == 0:
            my_list.append(i)

    if sum(my_list) == n:
        return f'{n} is a perfect number.'
    else:
        return f'{n} is not a perfect number.'
        
# Driver code
#print(is_perfect_number(6))