#Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

#Example 1:

'''Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23'''

class Solution:
    def maxSubArray(self, s):
        mx = float('-inf')
        for i in range(len(s)):
            s[i] = max(s[i], float('-inf') if i == 0 else s[i] + s[i-1])
            mx = max(mx, s[i])
        return mx