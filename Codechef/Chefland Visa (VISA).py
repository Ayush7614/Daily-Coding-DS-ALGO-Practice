t = int(input())         
for i in range(t):
    temp = input()
    n = temp.split(" ")
    if ((n[1] >= n[0]) and (n[3] >= n[2]) and (n[5] <= n[4])):
        print("YES")
    else:
        print("NO")
