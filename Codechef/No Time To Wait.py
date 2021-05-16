#Problem Link: https://www.codechef.com/MARCH21C/problems/NOTIME

n, h, x = map(int, input().split())
li = list(map(int, input().split()))
if max(li)+x>=h:
    print("YES")
else:
    print("NO")
