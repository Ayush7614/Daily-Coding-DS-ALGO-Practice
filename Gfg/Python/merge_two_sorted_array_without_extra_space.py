# Merging two sorted arrays without extra space
 
# find next gap(means find the gap between two elements to be compared .)
def findGap(gap):
    if (gap <= 1):
        return 0
    return (gap // 2) + (gap % 2)# ceiling value of gap.
#Lets merge arrays now.
def merge(arr1, arr2, n, m):
    gap = n + m #sum of sizes of 2 arrays.
    gap = findGap(gap)
    while gap > 0:
        # comparing elements 
        i = 0
        while i + gap < n:
            if (arr1[i] > arr1[i + gap]):
                arr1[i], arr1[i + gap] = arr1[i + gap], arr1[i]
            i += 1
 
       # comparing elements in both arrays.
        
        if gap > n:
          j = gap - n 
        else :
          j=0
        while i < n and j < m:
            if (arr1[i] > arr2[j]):
                arr1[i], arr2[j] = arr2[j], arr1[i]
            i += 1
            j += 1
        if (j < m):
            # comparing elements in the

            # second array.
            j = 0
            while j + gap < m:
                if (arr2[j] > arr2[j + gap]):

                    arr2[j], arr2[j + gap] = arr2[j + gap], arr2[j]
 

                j += 1
        gap = findGap(gap)
 
if __name__ == "__main__":
 
    n=int(input("Enter size of array 1 : "))
    a1 = [ ]
    for i in range(n):
      ele=int(input())
      a1.append(ele)
    m=int(input("Enter size of array 2 : "))
    a2 = []
    for I in range(m):
      ele2=int(input())
      a2.append(ele2)

    merge(a1, a2, n, m)
 
    for i in range(n):

        print(a1[i], end=" ")

    for i in range(m):

        print(a2[i], end=" ")
