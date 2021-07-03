# Short Description  : FENCED MATRIX 
# This problem provides to make understand others the concept of list, 
# list comprehension, deep and shallow copy methods in Python. 
# The project can be performed on Jupyter Notebook or Google Colab.

#take input without using library ast
in_str=input()
#as the input is in the form --> m,n where m is number of rows and n is number of columns, so we will split it using comma as separator
in_str=in_str.split(',')
# number of rows : m
m=int(in_str[0])
# number of columns : n
n=int(in_str[1])

#make a list with n zeroes
final=[0]*n

#make a matrix of m such lists using list comprehensions
final=[list(final) for i in range(m)]

for i in range(m):
    for j in range(n):
        if i==0 or j==0 or i==m-1 or j==n-1:
            final[i][j]=1                        #changing the list without any copy method
            
#print in the fashion as shown in Sample output
for i in final:
    print(i)

# Test Case -1 : 
# Input: 4,5
# Output: 
# [1,1,1,1,1]
# [1,0,0,0,1]
# [1,0,0,0,1]
# [1,1,1,1,1]

# Test Case -2 :
# Input: 3,2
# Output: 
# [1,1]
# [1,1]
# [1,1]

# Test Case -3:
# Input: 3,3
# Output: 
# [1,1,1]
# [1,0,1]
# [1,1,1]
