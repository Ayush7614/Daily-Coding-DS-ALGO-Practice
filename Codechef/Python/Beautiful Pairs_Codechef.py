import collections
t=int(input())
for i in range(t):
    S=int(input())
    T=[int(ip) for ip in input().strip().split()]
    c=S*(S-1)
    ec=collections.Counter(T)
    for k,v in ec.items():
        if v>1:
            c-=v*(v-1)
    print(c)
