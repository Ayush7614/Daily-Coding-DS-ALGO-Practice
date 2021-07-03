#program to find union of 2 sorted arrays
def printUnion(arr1, arr2, m, n):

    i, j = 0, 0

    while i < m and j < n:

        if arr1[i] < arr2[j]:

            print(arr1[i])

            i += 1

        elif arr2[j] < arr1[i]:

            print(arr2[j])

            j+= 1

        else:

            print(arr2[j])

            j += 1

            i += 1
 

#to print remaining elements 

    while i < m:

        print(arr1[i])

        i += 1
 

    while j < n:

        print(arr2[j])

        j += 1

arr1 = [ ]

arr2 = [ ]

m = int(input("Size of Array 1 "))
for i in range(m):
  b=int(input("Enter element "))
  arr1.append(b)
  
n = int(input("Size of Array 2 "))
for i in range(n):
  a=int(input("Enter element "))
  arr2.append(a)
printUnion(arr1, arr2, m, n)

#Example
#size of Array 1 - 4
#elements 1 3 5 8
#size of Array 2 - 3
#elements 2 3 5 
#union 1 2 3 5 8 