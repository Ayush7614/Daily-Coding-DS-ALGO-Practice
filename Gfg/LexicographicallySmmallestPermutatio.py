"""
Lexicographically smallest permutation of size A having B integers
exceeding all preceeding integers
"""

from itertools import permutations

def SmallestPermutation(a,b):
    
    if a==b:
        return list(range(1,a+1))
        
    #Initialise the list to store list
    #of elements which are satisfying 
    #the given conditions 
    pos_list=[]
    
    main_list=list(permutations(range(1,a+1),a))
    
    for L in main_list:
        
        #pointers to count of elements which are greater than #previous elements
        c=0
        i=0
        j=1
        
        while (j<=len(L)-1):
        
            if L[j]>L[i]:
                i+=1
        
            elif i==j:
                c+=1
                j+=1
                i=0
        
            else:
                j+=1
                i=0
        
        if((c+1)==b):
            pos_list.append(list(L))
    
    if len(pos_list)==1:
        return pos_list[0]

    satisfied_list=[]

    for i in pos_list:
        array_test=''.join(map(str,i))
        satisfied_list.append(int(array_test))
        
    small=min(satisfied_list)
    str_arr=list(str(small))
    ans=list(map(int,str_arr))
    
    return ans
    
a=3
b=2
print(SmallestPermutation(a,b))
    