# Problem Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler119/problem
import math
MAX = 10**100

def ConvertToBase(num, base):
    res = 0
    digits = 0
    
    while(num > 0):                
        res += int(num % base)
        digits += 1
        num //= base
    
    return res if digits >= 2 else -1    

B = int(input())
ans = set()
limit = 999 if B <= 10 else (B * 50)

for i in range(2, limit + 1):    
    p = i * i
    
    while(p < MAX):        
        if(p < B): 
            p *= i
            continue
        digit_sum = ConvertToBase(p, B)                
        
        if(digit_sum == i): ans.add(p)
        p *= i

output = [str(num) for num in sorted(list(ans))]
print(" ".join(output))
