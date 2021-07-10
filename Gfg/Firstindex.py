def firstIndex(arr, x):
    size=len(arr)
    if size<=0:
        return -1
    if x==arr[0]:
        return 0
    samllAns = firstIndex(arr[1:], x)
    if samllAns == -1:
        return -1
    else :
        return smallAns+1
    pass

# Main
from sys import setrecursionlimit
setrecursionlimit(11000)
n=int(input())
arr=list(int(i) for i in input().strip().split(' '))
x=int(input())
print(firstIndex(arr, x))

'''
Test case 
10
21 22 46 12 61 21 33 16 99 96 
25
output
-1
'''
