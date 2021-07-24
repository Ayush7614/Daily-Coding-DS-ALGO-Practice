//Link to the problem
/*
 https://leetcode.com/problems/perfect-squares/
 */

//According to the problem:
//Given an integer n, return the least number of perfect square numbers that sum to n.

//AIM: A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

/*Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4..
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);//created a dp array
        dp[1] = 1;//taking 1
        
        for(int i =2; i<=n;i++){
            int ans = INT_MAX;
            for(int j = 1; j*j <=i;j++){//traversing till root of n
                int rem = i - (j*j);
                ans = min(dp[rem], ans);..storing min val
            }
            dp[i] = ans + 1;//adding to ans
        }
        return dp[n];//returning  least number of perfect square numbers that sum to n.
    }
};