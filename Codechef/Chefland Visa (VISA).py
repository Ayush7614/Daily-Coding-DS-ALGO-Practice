t = int(input())         
for i in range(t):
    temp = input()
    n = temp.split(" ")
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