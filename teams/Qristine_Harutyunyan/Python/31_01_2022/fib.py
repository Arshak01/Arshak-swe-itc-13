def fib(n):
	if n < 0:
		print("Incorect")
	elif n == 0:
		return 0
	elif n == 1:
		return 1
	else:
		return fib(n - 1) + fib(n - 2)

print(fib(5))			



def fibLoop(n):
	f = [0, 1]
	for i in range(2, n + 1):
		f.append(f[i - 1] + f[i - 2])
	return f[n]

print(fibLoop(6))				
