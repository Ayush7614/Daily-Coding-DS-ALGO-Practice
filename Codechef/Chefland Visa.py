T=int(input())
for _ in range(T):
    n=input()
    c=n.split(" ")
    a=0
    
    if(c[3]>= c[2]):
         a+=1

    if(c[0]<= c[1]):
        a+=1
   
    if (c[5]<=c[4]):
        a+=1
    
        
    if (a==3):
        print("YES")
    else:
        print("NO")
