#Find the smallest positive number #missing from an unsorted array

#Link to problem https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/832/
def findMissing(a, n):
  

    for i in range(n) :
 

        # if value is negative or greater than array size then we skip the current iteration.
        if (a[i] <= 0 or a[i] > n):

            continue
 

        v = arr[i] #storing the  current unmarked value in a variable
 
         #traverse the array until we reach at an unmarked or already marked element

        while (a[v - 1] != v):

            nextval = a[v - 1]

            a[v - 1] = v

            v = nextval

            if (v <= 0 or v > n):

                break
 

    for i in range(n):

        if (a[i] != i + 1) :

            return i + 1
 

    # after marking all the elements return array size +1

    return n + 1
 
# Input 

if __name__ == "__main__":
    n=int(input())

    arr = [ ]
    for i in range(n):
      b=int(input())
      arr.append(b)

    d = findMissing(arr, n )

    print("The smallest positive missing number is \n ",d)
 
#Time Complexity: O(n) 
#Auxiliary Space: O(1)