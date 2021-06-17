#take input on your own here using library 'ast'
import ast
my_list = ast.literal_eval(input())
#as the input is in the form --> m,n where m is number of rows and n is number of columns
# number of rows : m
m = my_list[0]

# number of columns : n
n = my_list[1]

#start writing code here
final = [0]*n

#make a matrix of m such lists using list comprehensions
final = [list.copy(final) for i in range(m)]

for i in range(m):
    for j in range(n):
        if i==0 or j==0 or i==m-1 or j==n-1:
            final[i][j]=1
copy1 = list.copy(final)   #copying the list using shallow copy method

#print in the fashion as shown in Sample output
for i in copy1:
    print(i)



