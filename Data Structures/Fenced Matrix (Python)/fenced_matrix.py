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



