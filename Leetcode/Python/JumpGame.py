"""
Greedy Algorithm
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.
"""

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        leftind = n = len(nums) - 1
        for i in range(n,-1,-1):
            if (i + nums[i]) >= leftind:
                leftind = i
        return leftind == 0
obj = Solution()
nums = list(map(int,input().split()))
print(obj.canJump(nums))