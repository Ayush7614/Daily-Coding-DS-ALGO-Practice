// Problem link - https://leetcode.com/problems/partition-equal-subset-sum/
// Description - Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
// Testcases
// Input
// [1,5,11,5]
// Output
// true 
// **************
// Input
// [1,2,3,5]
// Output
// false
// **************

// This problem can be solved using the approach of a standard dp problem 0-1 Knapsack
class Solution {
    public boolean canPartition(int[] nums) {
        int n=nums.length ;
        int sum=0 ;
        for(int i:nums) sum+=i ;
        // if size is odd not possible to split the array into two groups
        if(sum%2!=0) return false ;
        // we need to find that if we can make a group of some elements whose sum is maximum capacity of bag
        // here is the maximum capacity of bag is sum/2
        int cap=sum/2 ;
        cap++ ;
         boolean[][] dp = new boolean[n][cap];
        for(int i=0;i<cap;i++) if(nums[0]==i) dp[0][i]=true;
        for(int i=0;i<n;i++) dp[i][0]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<cap;j++){
                dp[i][j]=dp[i-1][j] ;
                if(!dp[i][j]) {
                    if(nums[i]<=j) dp[i][j]=dp[i-1][j-nums[i]] ;
                }
            }
        }
        // if the required capacity is possible to achieve.
        return dp[n-1][cap-1] ;
        
    }
}

// Time Complexity- O(N*N) where N is the size of the input array