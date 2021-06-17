import math 
t = int(input())        #taking input of test cases 
for i in range(t): 
    s = int(input())    #s denotes number of gold coin
    d= (1+8*s)          
    d= int (math.sqrt(d))   
    n = int((-1+d)/2)       
    print(n)
#this is a simple AP(Arithmatic Progression) problem
# we used the sum of AP formula S = n/2(2a+ (n-1)diff)
# here a = first term(1 in this case), diff= common difference(1 in this case), n=number of terms(to be found),s = sum(total coins)
#solving the above eqaution we get n^2+n-2s=0 
#to find the root of the above eq we used n = (-b+sqrt(b^2-4ac))/2a, output n

# Sample input/output

# Input
# 3
# 3
# 5
# 7

# Output
# 2
# 2
# 3
