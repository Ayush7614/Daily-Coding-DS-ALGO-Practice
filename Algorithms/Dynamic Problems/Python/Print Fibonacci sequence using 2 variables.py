# Simple Python3 Program to
# print Fibonacci sequence

def fib(n):
	a = 0
	b = 1
	if (n >= 0):
		print(a, end=' ')
	if (n >= 1):
		print(b, end=' ')
	for i in range(2, n+1):
		c = a + b
		print(c, end=' ')
		a = b
		b = c

# Driver code
fib(9)

