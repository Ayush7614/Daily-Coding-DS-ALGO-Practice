#Link to the problem
#https://leetcode.com/problems/shortest-common-supersequence/
#program to find length of the shortest supersequence
def shortestSupSeq(A, B):
  
#So,the task is to find a string which includes both the given strings
#(that is subsequences)and is the shortest.If both strings have nothing 
#in common then the answer is sum of length of both the strings.If the 
#strings have something in common then we don't want to repeat the common characters.
#so,we find lcs of both strings and count the occurrence only once and count unique characters.
  x = len(A)
  y = len(B)
  l = lcs(A, B, x, y)
  return (x+ y - l)
  
  
#to find lcs.
def lcs(X, Y, m, n):

    L = [[0] * (n + 2) for i in range(m + 2)]
 



    for i in range(m + 1):
 

        for j in range(n + 1):
 

            if (i == 0 or j == 0):

                L[i][j] = 0
 

            elif (X[i - 1] == Y[j - 1]):

                L[i][j] = L[i - 1][j - 1] + 1
 

            else:

                L[i][j] = max(L[i - 1][j],

                              L[i][j - 1])
 



    return L[m][n]
    
    
A =input()

B= input()
 

print("Length of the shortest supersequence is \n", shortestSupSeq(A, B))

#Example
#abcde
#cd
#Output:-6 
