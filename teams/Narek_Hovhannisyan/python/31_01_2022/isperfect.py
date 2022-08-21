def is_perfect(num):
    tmp_sum = 0
    for n in range(1, num // 2 + 1):
        if num % n == 0:
            tmp_sum += n
    return tmp_sum == num


print(is_perfect(12))
print(is_perfect(36))
print(is_perfect(6))
print(is_perfect(28))
print(is_perfect(496))
print(is_perfect(8128))

