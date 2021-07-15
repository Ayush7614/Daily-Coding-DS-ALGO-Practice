# program to check if n is present in an array.
#we can do it using linear Search or binary Search
#linear search approach
#def linearSearch(a,n):
#  for i in  range(len(a)):
#    if a[i]==n:
#      return True
  
#  return False
  
  

#binary search approach
def binarySearch(a,n):
  l=0
  h=len(a)-1;
  if l<=h:
    mid=(l+h)//2
    if a[mid]==n:
      return True
    elif a[mid]>n:
      h=mid-1
    else :
      l=mid+1
  return False
      
    
arr=[]
m=int(input("Enter size of array : "))
for i in range(m):
  e=int(input())
  arr.append(e)
n=int(input("Enter element to be searched  : "))
#print(linearSearch(arr,n))
print(binarySearch(arr,n))

#Example:
#size = 5
# 5 4 0 1 2
#1
#true 

