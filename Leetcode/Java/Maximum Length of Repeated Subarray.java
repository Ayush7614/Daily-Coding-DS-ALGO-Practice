// Question  https://leetcode.com/problems/maximum-length-of-repeated-subarray/

// Solution
class Solution {
    public int findLength(int[] A, int[] B) {
        int dp[][] = new int[A.length+1][B.length+1];
        int max = 0;
        for(int i = 0; i <= A.length; i++) {
            for(int j= 0; j <= B.length; j++) {
                if(i == 0 || j == 0 || A[i-1] != B[j-1]) dp[i][j] = 0;
                else {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    max = Math.max(max, dp[i][j]);
                }
            }
        }
    return max;
    }
}