# Import permutation function from itertools
from itertools import permutations

# Get input from the user
n=int(input("Enter a number: "))
# Create a list by coonverting n into a string
lst=[x for x in str(n)]
# Get all permutations of the string n
lst = list(permutations(lst))
# Create an empty list to store the permutations in initeger format
num = []
for i in lst:
    s = ''.join(i)
    num.append(int(s))
# Remove the original number to find the second smalled
# number which will be the nearest number to n
num.remove(x)
# To find and store the minimum difference
diff = 0
minval = num[0]
for i in num:
    x = abs(i - x)
    if diff > x:
        diff = x
        minval = i

# Print the answer
print(minval)