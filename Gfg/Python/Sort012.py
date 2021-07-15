def sort012( a, arr_size):
  lo = 0
  hi = arr_size - 1
  mid = 0
  while mid <= hi:
    if a[mid] == 0:
      a[lo], a[mid] = a[mid], a[lo]
      lo = lo + 1
      mid = mid + 1
    elif a[mid] == 1:
      mid = mid + 1
    else:
      a[mid], a[hi] = a[hi], a[mid] 
      hi = hi - 1
  return a

# Function to print array
def printArray( a):
  for k in a:
    print(k)


n=int(input("Size"))
arr=[]
for i in range(0,n):
  b=int(input("Enter array elements"))
  arr.append(b)
arr=sort012(arr,n)

print ("Array after segregation :\n")
printArray(arr)

