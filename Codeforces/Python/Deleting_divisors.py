#Deleting Divisors
for _ in range(int(input())):
    n = int(input())
    cnt = 0
    if n%2==1:
        print("Bob")
        continue
    while n%2==0:
        cnt+=1
        n//=2
    if n>1 or cnt%2==0:
        print("Alice")
    else:
        print("Bob")
        
        
#Example:-
#input 
# 4
#1
#4
#12
#69

#output
# Bob
# Alice
# Alice
#;Bob

