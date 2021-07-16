#import python packages
from collections import deque

Find the next greater element for every element in a list
def findNextGreaterElements(L):
result = [-1] * length(A)

# create an empty stack
t = deque()
#this is the solution for next greater element using python

# do for each element
for i in range(length(A)):

    # loop till we have a greater element on top or stack becomes empty.

    # Keep popping elements from the stack smaller than the current
    # element, and set their next greater element to the current element
    while t and A[t[-1]] < L[i]:
        result[t[-1]] = A[i]#result
        t.pop()
#poping the element
# push current "index" into the stack
t.append(i)

return result
#this is the end of the progra
if name == 'main':

A = [11,13,21,3,1]
print(findNextGreaterElements(L))#giving the input 


###
Test cases


A = [11,13,21,3,1]


11 -- 13
13 -- 21
21 -- -1
3 -- -1

###

