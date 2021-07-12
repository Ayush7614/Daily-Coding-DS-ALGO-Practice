#Last index of an array.
def lastIndex(arr, x):
    l = len(arr)#length of array 
    #Base case is if the size of array is 0 then return -1 
    if l == 0:
        return -1
    
    smallerList = arr[1:]
    smallerListOutput = lastIndex(smallerList, x)#recursion - search in smaller array
    #if smaller array does not return -1 then ans is ans+1
    if smallerListOutput != -1:
        return smallerListOutput +1 
        #else if element is not found in smaller array then check if 0th element is equal to the number
    else:
        if arr[0] == x:
            return 0
        else:
            return -1
            
arr=[]
n=int(input("Enter size of array"))
for i in range(n):
  e=int(input("Enter element : "))
  arr.append(e)
x=int(input())
print(lastIndex(arr,x))
#Example
#5
#3 4 5 6 5 
#5
#Output 4