#Solution to the ICPC Balloon Problem
#Taking Testcases
for t in range(int(input())):
    #Input Code N & Array
    N = int(input())
    A = list(map(int, input().split()))
    

#Actual Problem's Solution Begun
    i = 0
    s = set()
    while i < N:
        if A[i] <= 7:
            s.add(A[i])
        if len(s) == 7:
            break
        i+=1
    print(i+1) if i<N else print(i)

'''
Examples:

Input 1:
N=7
Array=[1 ,2 ,3 ,4 ,5 ,7 ,6]

Output 1:
7

-----------------------------

Input 2:
N=9
Array=[7 ,4 ,3 ,5 ,6 ,1 ,8 ,2, 9]

Output 2:
8

'''
            