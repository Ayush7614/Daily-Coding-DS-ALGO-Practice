# Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler020/problem

def factorial(n):
    p = 1
    for i in range(1, n+1):
        p *= i
    return p

for _ in range(int(input())):
    ls = str(factorial(int(input())))
    sum = 0
    for i in ls:
        sum += int(i)
    print(sum)
