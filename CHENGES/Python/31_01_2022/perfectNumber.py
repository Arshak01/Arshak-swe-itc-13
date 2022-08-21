
def perfectNumber(num):
    sum = 0
    for i in range(1,num):
        if num % i == 0:
            sum+=i
    if num == sum:
        print(f'{num} is perfect number. ')
    else:
        print(f'{num} isn\'t perfect number. ')

num = int(input("Entry number : "))
perfectNumber(num)
