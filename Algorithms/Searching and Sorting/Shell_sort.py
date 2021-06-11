# Function to perfoorm shell sort
def shellsort(lst):
    # Get the length of the list
	n = len(lst)
    # Find the interval by dividing the length by 2
	interval = n // 2
    # Make sure the interval is a positive number
	while interval > 0:
        # Iterating and comparing every i element with i-interval element
		for i in range(interval, n):
			while i - interval >= 0 and lst[i] < lst[i - interval]:
                # Sorting the i element and di-interval element if necessary
				lst[i], lst[i - interval] = lst[i - interval], lst[i]
                # Reducing the value of i by 1 to take the next i and i-interval
                # elements into comparison
				i = i - interval
        # Reducing the interval by half
		interval = interval // 2
    # Returns the sorted list
	return lst

# Unordered list to be sorted
lst = [7, 5, 3, 1, 5, 9, 8, 4, 6, 2, 10]
# Printing the sorted list
print(shellsort(lst))