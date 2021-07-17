# median of 2 sorted arrays
def Solution(arr):
    n = len(arr)
    # If length of array is even
    if n % 2 == 0:
        i = n // 2 #divide the length of array by 2
        e = arr[i]
        q = arr[i - 1]
        ans = (e + q) / 2
        return ans
         
    # If length of array is odd
    else:
        i = n // 2 #divide the length of array by 2 and round off
        ans = arr[i]
        return ans
 
if __name__ == "__main__":
    n=int(input("Size of array 1 : "))
    arr1 = []
    for i in range(n):
      e=int(input())
      arr1.append(e)
    m=int(input("Size of array 2: "))
  
    arr2 = []
    for j in range(m):
      f=int(input())
      arr2.append(f)
    # Concatenating the two arrays

    arr3 = arr1 + arr2
 

    # Sorting the resultant array

    arr3.sort()
 

    print("Median = ", Solution(arr3))

#Example
#Input : ar1[] = {2, 3, 5, 8}
 #       ar2[] = {10, 12, 14, 16, 18, 20}
#Output : The median is 11.