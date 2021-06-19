''' 
Problem statement: Find position of setbit. If there are 0 or morethan 1 set bit then print as "Invalid number" else
print position of setbit.
    If number is power of 2 then its binary representation contains only one ‘1’. So,check whether the
 given number is a power of 2 or not. If given number is not a power of 2, then print as Invalid number
 and exit. We can check a given number n is power of 2 or not by doing "and" operation between n and n-1 .
 If it is zero,then the given number n is power of 2.
 
'''
def findPosition(n):  #Finding position of setbit
    if(powerofTwo(n)==False):
        return -1
    count=0
    while(n!=0):
        n=n>>1
        count+=1
    return count
def powerofTwo(n): #Checking given number is power of 2 or not.
    if(n==0):
        return False
    return (n&(n-1))==0
n=int(input())
pos = findPosition(n)
if (pos == -1):
    print("n =", n, ", Invalid number")
else:
    print("n =", n, ", Position ", pos)