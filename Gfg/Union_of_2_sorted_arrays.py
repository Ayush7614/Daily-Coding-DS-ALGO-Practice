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
 

    while i < m:

        print(arr1[i])

        i += 1
 

    while j < n:

        print(arr2[j])

        j += 1
 

m=int(input("Size of first array"))

arr1 = [ ]

arr2 = [ ]
for i in range(m):
  a=int(input("element"))
  arr1.append(a)
n=int(input("Enter size of second array"))
for j in range(n):
  b=int(input("element"))
  arr2.append(b)

printUnion(arr1, arr2, m, n)

#Example
# Input : arr1[] = {1, 3, 4, 5, 7}
# arr2[] = {2, 3, 5, 6}
# Output : Union : {1, 2, 3, 4, 5, 6, 7}