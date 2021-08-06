/*
Leetcode Problem 53. Maximum Subarray (Easy)

Given an integer array nums, find the contiguous subarray 
(containing at least one number) 
which has the largest sum and return its sum.

Approach in c++

Example 1 :
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2 :
Input: nums = [1]
Output: 1

Constraints : 
1 <= nums.length <= 3 * 104
-105 <= nums[i] <= 105
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
          int n = nums.size();
    if(n == 0)
    {
        return 0;
    }
    
    int ans = INT_MIN;
    int sum = 0;   //initalizing with 0 to discard -ve values
    
    for(int i=0; i<n; i++) //for loop with O(n) time complexity
    {
        sum += nums[i];
        
        ans = max(ans, sum); 
		
       if(sum < 0){
            sum = 0;
        }
    }
    
    return ans;
}
 };