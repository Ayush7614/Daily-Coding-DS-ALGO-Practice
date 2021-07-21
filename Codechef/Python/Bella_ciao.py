def func(D,d,p,q):
    x=D//d
    count=((x)*(2*p+(x-1)*q))//2
    return count;
    
t=int(input())
for i in range(t):
    D,d,p,q=map(int,input().split())
    y=D%d
    c=y*(p+q*(D//d))
    x=d*(func(D,d,p,q))+c
    print(x)