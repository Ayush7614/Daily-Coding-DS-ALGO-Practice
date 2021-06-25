def leftRotate(arr, d, n):

    for i in range(d):

        leftRotatebyOne(arr, n)
 
#Function to left Rotate arr[] of size n by 1*/ 

def leftRotatebyOne(arr, n):

    temp = arr[0]

    for i in range(n-1):

        arr[i] = arr[i+1]

    arr[n-1] = temp

         
 
# utility function to print an array */

def printArray(arr,size):

    for i in range(size):

        print ("%d"% arr[i],end=" ")
 

  
# Driver program to test above functions */

arr = []
n=int(input("Size "))
for i in range(0,n):
  b=int(input("Array element "))
  arr.append(b)
d=int(input("Enter by how many elements to rotate array "))
leftRotate(arr,d,n)
printArray(arr,n)