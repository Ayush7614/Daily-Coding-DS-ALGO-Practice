for _ in range(int(input())):
    N,D,H=map(int,input().split())
    A=list(map(int,input().split()))
    a=0
    flag=True
    for i in A:
        if i>0:
            a+=i
        elif i==0 and a>=D:
            a-=D
        else:
            a=0
        if a>H:
            print("YES")
            flag=False
            break
    if  flag:
        print("NO")
