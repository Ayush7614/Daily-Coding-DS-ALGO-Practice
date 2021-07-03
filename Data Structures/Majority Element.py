# Problem Statement Given an array nums of size n, return the majority element.
#The majority Element is the element that appears more than [n/2] times.
#You may assume that the majority element  always exist in the array. 

#Constraints:

#n == nums.length
#1 <= n <= 5 * 10^4
#-2^31 <= nums[i] <= 2^31 - 1



class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        return nums[len(nums)//2]


#Test Cases:
#Example 1:
#Input: nums = [3,2,3]
#Output: 3
#Example 2:
#Input: nums = [2,2,1,1,1,2,2]
#Output: 2

# Run Code Result:
#Your input
#[3,2,3]
#Output
#3
#Expected
#3


#Space Complexity: O(1)
# Time Complexity:O(n)

