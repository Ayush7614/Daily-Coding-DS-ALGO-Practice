# Intro:
# Here we have to check if x2 >= x1 and y2 >= y1 and z2 <= z1, if all this conditions statisfies then print "YES" else "NO"
# In the given solution:
# x1 = n[0]
# x2 = n[1]
# y1 = n[2]
# y2 = n[3]
# z1 = n[4]
# z2 = n[5] 

t = int(input())            # Taking input for number of test cases  
for i in range(t):
    temp = input()
    n = temp.split(" ")     # Spliting the string temp based on spaces to get individual element
    if ((n[1] >= n[0]) and (n[3] >= n[2]) and (n[5] <= n[4])):
        print("YES")
    else:
        print("NO")

# Sample input/output

# Example Input
# 4
# 20 50 2100 1900 6 6
# 50 20 1900 1900 5 5
# 20 20 1900 1900 1 6
# 27 27 1920 1920 3 3

# Example Output
# NO
# NO
# NO
# YES