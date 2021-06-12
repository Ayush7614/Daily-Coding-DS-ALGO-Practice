#program to match the string with pattern using modular algorithm
def reGexMatch(s,p):
    #lookuptable
    #initalize the 2D array dp with None/null of size length of pattern+1 & string+1.
    #inorder to tranverse the 2D array two iterative variables required i & j.
    dp=[[None for j in range(len(s)+1)] for i in range(len(p)+1)]
    for i in range(len(dp)):
        for j in range(len(dp[0])):
          #the very first index is always True because blank is matches with only blank
            if i==0 and j==0: dp[i][j]=True
              #first row i.e. zeroth row of dp is always False.
            elif i==0: dp[i][j]=False
              #zeroth column of dp check for "*" & update the current dp[i][j] = value behind the two indexes of i.
            elif j==0:
                if p[i-1]=='*':
                    dp[i][j]=dp[i-2][j]
                else:
                    dp[i][j]=False
             # describes array indexes except zeroth row & zeroth column
            else:
                #if array index caught "*" evaluate (two indexes behind the array column and beside the element) 
                if p[i-1]=='*':
                    dp[i][j]=dp[i-2][j]
                    if p[i-2]==s[i-1] or p[i-2]=='.':
                        dp[i][j]=dp[i][j] or dp[i][j-1]
                #if character matches and caught "." in pattern update the current index with diagonal value
                elif p[i-1]=='.':
                    dp[i][j]=dp[i-1][j-1]
                #if anyone index is true , current dp index is true
                elif p[i-1]==s[j-1]:
                    dp[i][j]=dp[i-1][j-1]
                else:
                    #else all other cases are False.
                    dp[i][j]=False
    return "Yes-Matched" if dp[len(p)][len(s)] else "No-Mismatch"
  
  #driver code
s="crosssection"
p="cros*ect.*"
print(reGexMatch(s, p))