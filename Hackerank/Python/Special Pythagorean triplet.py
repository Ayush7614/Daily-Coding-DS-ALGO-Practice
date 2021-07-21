# Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler009/problem

for _ in range(int(input())):
    N = int(input())
    ls = list()
    for a in range(1, N):
        b = (N*N-2*a*N)/(2*N-2*a)
        if b!=int(b) or b<=a:
            continue
        else:
            b=int(b)
        c = N-a-b
        if c<=b:
            continue
        ls.append(a*b*c)
    if ls:
        print(max(ls))
    else:
        print("-1")
