def allIndexes(input, x, start):

    
    # If the start index is equal to end of array then return empty array 
    if (start == len(input)):
        ans = [] 
        return ans
 

    # recursion

    smallIndex = allIndexes(input, x,start + 1)
    # If the element at start index is equal to x then put the start in first index of array.
    if (input[start] == x):
        myAns = [0 for i in range(len(smallIndex) + 1)]
        myAns[0] = start
        for i in range(len(smallIndex)):
 
            # Shift the elements of the array by 1 to right 
            myAns[i + 1] = smallIndex[i]
        return myAns
    else:
        return smallIndex
 

def allIndices(input, x):
    return allIndexes(input, x, 0)
 
n=int(input("Enter size of array : "))
arr = [ ]
for i in range(n):
  e=int(input())
  arr.append(e)

x = int(input())
 
output=allIndices(arr, x)
 
# Printing the output array

for i in output:

    print(i, end = " ")
#Example
#Input 5
#6 5 6 7 5
#Output 
#0,2