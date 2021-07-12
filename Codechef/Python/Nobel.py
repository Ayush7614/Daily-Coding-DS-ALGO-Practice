#Problem Link: https://www.codechef.com/START2C/problems/NOBEL

t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    li = list(map(int, input().split()))
    f = 0
    s = set(li)
    if len(s)==m:
        print("No")
    else:
        print("Yes")
        