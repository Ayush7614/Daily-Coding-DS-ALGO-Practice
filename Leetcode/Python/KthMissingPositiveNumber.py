#Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

#Find the kth positive integer that is missing from this array.

'''Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.'''


class Solution:
    
    def findKthPositive(self, arr: list[int], k: int) -> int:
        if k < arr[0]:
            return k
        l, r = 0, len(arr) - 1
        
        while l <= r:
            mid = (l + r) // 2 # OR l + (r - l) // 2
            if arr[mid] - (mid + 1) < k:
                l = mid + 1
            else:
                r = mid - 1
        return l + k
        








        
