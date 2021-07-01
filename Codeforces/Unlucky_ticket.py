# Unlucky Ticket
#Link to the problem:-https://codeforces.com/problemset/problem/160/B

# For example: 2421 2> 1, 4> 2
# That meets the lucky number requirement;

# 0135
#0 < 3,1 < 5，

#That meets the non-lucky number requirement;

n = int(input())
s = input()

s1 = sorted(s[:n])
s2 = sorted(s[n:])

less = False
more = False

for i in range(n):
    if i == 0:
        if int(s1[i]) < int(s2[i]):
            less = True
        elif int(s1[i]) > int(s2[i]):
            more = True
        else:
            print('NO')
            break
    else:
        if int(s1[i]) < int(s2[i]) and not less:
            print('NO')
            break
        elif int(s1[i]) > int(s2[i]) and not more:
            print('NO')
            break
        elif int(s1[i]) == int(s2[i]):
            print('NO')
            break
else:
    print('YES')
    
    
    
#Example
#2 
#2421
#Output:- Yes 
