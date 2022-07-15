
/*

Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
Example 2:

Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
Example 3: 

Input: n = 5
Output: 68
 

Constraints:

1 <= n <= 2 * 10^4
   Hide Hint #1  
Use dynamic programming.
   Hide Hint #2  
Let dp[i][j] be the number of strings of length i that ends with the j-th vowel.
   Hide Hint #3  
Deduce the recurrence from the given relations between vowels.


*/


class Solution {
public:
    int countVowelPermutation(int n) {
        
        int mod=1000000007;
        long long int dp[n+1][5];
        
        for(int i=0;i<5;i++) {
            dp[1][i]=1;
        }
        
        int a=0,e=1,i1=2,o=3,u=4;
        
        for(int i=2;i<n+1;i++) {
            dp[i][a]=dp[i-1][e]%mod;
            dp[i][e]=(dp[i-1][a]%mod+dp[i-1][i1]%mod)%mod;
            dp[i][i1]=(dp[i-1][a]%mod+dp[i-1][e]%mod+dp[i-1][o]%mod+dp[i-1][u]%mod)%mod;
            dp[i][o]=(dp[i-1][i1]%mod+dp[i-1][u]%mod)%mod;
            dp[i][u]=(dp[i-1][a])%mod;
        }
        
        return (dp[n][a]%mod+dp[n][e]%mod+dp[n][i1]%mod+dp[n][o]%mod+dp[n][u]%mod)%mod;
        
    }
};