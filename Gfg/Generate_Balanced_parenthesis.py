'''
Given: N=2


Output:
(())
()()


now to form all of the sequences of these balanced bracket subsequencefor n. 
we know that there are n opening brackets and n closing brackerts with us.

so subsequence will be of length = (length*2) 

so we're going with a naive type of Approach like



Case 1-> The i'th character can be (  if and only if the number of occurences of ( till i'th index is less than the length of n
Case 2-> The i'th character can be ) if and only if the th number of occurences of ) is greater than the count of ) till i'th index

So, if these two cases are followed then resulting subsequence will be always balanced and we can print that in our answer

-



'''

def printParenthesis(str, n):
    if(n > 0):
        _printParenthesis(str, 0,
                          n, 0, 0);
    return;
 
def _printParenthesis(str, pos, n,
                      open, close):
     
    if(close == n):
        for i in str:
            print(i, end="");
        print();
        return;
    else:
        if(open > close):
            str[pos] = ')';
            _printParenthesis(str, pos + 1, n,
                              open, close + 1);
        if(open < n):
            str[pos] = '(';
            _printParenthesis(str, pos + 1, n,
                              open + 1, close);
 

n = int(input("Enter length of parenthesis "));
print("\n")
str = [""] * 2 * n;
printParenthesis(str, n);


'''
    Time Complexity: O(2^n). 
For every index there can be two options ( or ) . So it can be said that the upperbound of time complexity is O(2^n) or it has exponential time complexity.
Space Complexity: O(n). 

The space complexity can be reduced to O(n) if global variable or static variable is used to store the output string.
'''
