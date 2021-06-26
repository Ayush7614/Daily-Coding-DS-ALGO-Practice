#Find the smallest positive number #missing from an unsorted array

#Link to problem https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/832/
def findMissingNo(arr, n):
  
    # to store next array element in

    # current traversal

    for i in range(n) :
 

        # if value is negative or greater
        # than the array size, then it #cannot be marked in array. So #move to
        # next element.

        if (arr[i] <= 0 or arr[i] > n):

            continue
 

        val = arr[i]
 

        # traverse the array until we
        #reach at an element which
         #is already marked or which #could not be marked.

        while (arr[val - 1] != val):

            nextval = arr[val - 1]

            arr[val - 1] = val

            val = nextval

            if (val <= 0 or val > n):

                break
 

    # find first array index which is

    # not marked which is also the

    # smallest positive missing

    # number.

    for i in range(n):

        if (arr[i] != i + 1) :

            return i + 1
 

    # if all indices are marked, then

    # smallest missing positive

    # number is array_size + 1.

    return n + 1
 
# Input 

if __name__ == "__main__":
    n=int(input())

    arr = [ ]
    for i in range(n):
      b=int(input())
      arr.append(b)

    missing = findMissingNo(arr, n )

    print("The smallest positive missing number is \n ",missing)
 
#Time Complexity: O(n) 
#Auxiliary Space: O(1)