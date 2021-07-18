#Problem Link: https://www.codechef.com/START2C/problems/T20MCH
r, o, c = map(int, input().split())
if c+36*(20-o)>r:
    print("YES")
else:
    print("NO")