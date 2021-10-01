//------------------------ Minimum Size Subarray sum ----------------

//Problem Link - https://leetcode.com/problems/minimum-size-subarray-sum/

/*Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is 
greater than or equal to target. If there is no such subarray, return 0 instead.

 
Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0  */
 
/* Logic : we have kept the starting index of subarray fixed, and found the last position. Instead, we could move the starting index of the current subarray as soon as we know that no 
better could be done with this index as the starting index. We could keep 2 pointer,one for the start and another for the end of the current subarray, and make optimal moves so as to
 keep the sum greater than s as well as maintain the lowest size possible. */


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
          int n=nums.size();
          int ans=n,sum=0,s;
        
          for(int i=0;i<n;i++)
              sum=sum+nums[i];
          if(sum<target)
               return 0;
          else if(sum==target)
               return n;
        
          sum=0;
          int start=0;
          for(int i=0;i<n;i++)
          {
              sum=sum+nums[i];
              while(start<=i and sum>=target)
              {
                  sum=sum-nums[start];
                  ans=min(ans,i-start+1);
                  start++;
              }
          }
          return ans;
    }
};
