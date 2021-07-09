/*                                          LEETCODE PROBLEM - #42 (HARD)
                                                Trapping Rain Water

Link to Problem: https://leetcode.com/problems/trapping-rain-water/

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example:

Input  
[0,1,0,2,1,0,1,3,2,1,2,1]

Output
6

**********Approach 1: Brute force**********

    Algorithm

    1. Initialize a variable ans = 0;
    2. Iterate the array from left to right:
        a. Initialize leftMax = 0 & rightMax = 0;
        b. Iterate from the current element to the beginning of array updating:
            leftMax = max(leftMax, height[j]);
        c. Iterate from the current element to the end of array updating:
            rightMax = max(rightMax, height[j]);
        d. Add min(leftMax, rightMax) - height[i] to ans


    This Approach will have a Time Complexity of O(n^2)
    And Space Complexity of O(1) - Constant Extra Space

    
**********Approach 2: Using 2 pointers **********

    This is the best approach as it has best Space and Time Complexity

    Algorithm

    1. Initialize left pointer to 0 and right pointer to size-1     
        int left = 0, right = height.size()-1;
    2. while left < right do,
        a. If height[left] is smaller than height[right]
            # If height[left] >= left_max, then update left_max
            # Else add left_max - height[left] to ans
            # Add 1 to left.
        
        b. else
            # If height[right] >= right_max, then update right_max
            # Else add right_max - height[right] to ans
            # Subtract 1 from right.
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if(height[left] >= left_max)
                    left_max = height[left];

                else   
                    ans += (left_max - height[left]);

                ++left;
            }
            else {
                if(height[right] >= right_max)
                    right_max = height[right];
                
                else
                    ans += (right_max - height[right]);
                
                --right;
            }
        }
        return ans;
    }
};

/*
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1) - Constant Extra Space Required

Runtime: 4 ms, faster than 89.38% of C++ online submissions for Trapping Rain Water.
Memory Usage: 14.1 MB, less than 96.08% of C++ online submissions for Trapping Rain Water.
*/