def isPerfect(n) :
    sum = 0
    for i in range(1,n) :
        if(n % i == 0) :
            sum += i
    if(sum == n) :
        print("The input number is perfect")
    else :
        print("The input number isn't perfect")

n = input("Please input the number: ")
isPerfect(n)