# Python3 program to Count occurrences
# of an element in a sorted array 
# Approach :Improved Binary Search
# Time Complexity : O(Logn)

# If x is present in a[] then 
# return the number of occurrences
# of x, otherwise returns -1.
# Example:
# Input : a[] = {1, 2, 2, 2, 2, 2, 3,}, x = 2
# Output : 5

def countocc(a, x, n):

	# to obtain the index of first occurence
  # of x in a[]
	i = first(a, 0, n-1, x, n)

	# If x absent in
	# a[] then return -1
	if i == -1:
		return i
	
	# If x present then obtain last occurence of x
  # in a[] but in subarray with starting index as i
	j = last(a, i, n-1, x, n);	
	
	# return count
	return j-i+1;

# If x is present in the array a[] then return
# the index of first occurrence of x 
# otherwise return -1
def first(a, low, high, x, n):
	if high >= low:
    
		mid = (low + high)//2	
		
		if (mid == 0 or x > a[mid-1]) and a[mid] == x:
			return mid
		elif x > a[mid]:
			return first(a, (mid + 1), high, x, n)
		else:
			return first(a, low, (mid -1), x, n)
	return -1;

# if x is present in a[] then return
# the index of last occurrence of x
# otherwise returns -1
def last(a, low, high, x, n):
	if high >= low:

		mid = (low + high)//2;

		if(mid == n-1 or x < a[mid+1]) and a[mid] == x :
			return mid
		elif x < a[mid]:
			return last(a, low, (mid -1), x, n)
		else:
			return last(a, (mid + 1), high, x, n)	
	return -1

a = [] 
# number of elemetns as input
n = int(input("Enter number of elements : "))
  
# iterating till one less then
# the number of elements given by user
for i in range(0, n):
    p = int(input())  
    a.append(p)
    
x = int(input("Enter the element to be counted : ")) # Element to be counted in a[]
n = len(a)
c = countocc(a, x, n)
print ("%d element occurs %d times "%(x, c))
