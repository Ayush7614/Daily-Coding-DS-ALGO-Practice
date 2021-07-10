#program to find range of Array 
#function to get minimum number in an array 
def getMin(arr, n):
  res = arr[0]
  for i in range(1, n, 1):
    res = min(res, arr[i])
  return res
 
# function to get maximum number from an array 
def getMax(arr, n):
  res = arr[0]
  for i in range(1, n, 1):
    res = max(res, arr[i])
  return res
 
# function to find range   
    
def findRange(arr, n):
  max = getMax(arr, n)
  min = getMin(arr, n)
  range = max - min
  print("Range :", range)
    
    
if __name__ == '__main__':

    arr = []

    n = int(input("size : "))
    for i in range(n):
      b=int(input("Array element : "))
      arr.append(b)
    findRange(arr, n)
    
    
#Example
#size : 3
#array element : 5
#array element : 10
#array element :15
#output:- 10
