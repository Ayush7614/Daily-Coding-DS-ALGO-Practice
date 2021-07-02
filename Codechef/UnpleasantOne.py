'''
A question called Unpleasant One from Code chef 
practice the question at https://www.codechef.com/LTIME97B/problems/UNONE/

Question:
You are given an array A of N integers 
and you have to find any ordering of the array 
such that the ugliness of the concatenated string of the binary 
representations of the integers (without leading zeros) is minimum.
'''

for a0 in range(int(input())):
    n=int(input())
    l=[int(x) for x in input().split()]
    m=dict()
    l1=[]
    l2=[]
    for i in range(n):
        x=bin(l[i])[2:]
        m[x]=l[i]
        if l[i]%2==0:
            l1.append(x)
        else:
            l2.append(x)
        l[i]=x 
    l1=sorted(l1,key=lambda x:len(x)-max((x+'0').index('0'),0),reverse=True)
    # l2=sorted(l2,key=lambda x:len(x)-max((x+'0').index('0'),0),reverse=True)
    # print(tmp,end=" ")
    for i in l1:
        print(int(i,2),end=" ")
    for i in l2:
        print(int(i,2),end=" ")
    print()

'''
Testcases:
2   #loop
------------------------------
3  
3 6 5  
Ans:
5 6 3
The binary representations of [5,6,3] are [101,110,11] 
and the concatenated string would be "10111011" which has ugliness 3.
This is the minimum possible. [6,5,3] is also valid.

------------------------------
2   
7 6
Ans:
6 7
The binary representations of [6,7] are [110,111] 
and the concatenated string would be "110111" which has ugliness of 3. 
This is the minimum possible. [7,6] is not valid as it has ugliness of 4.
'''
