/*                                 LEETCODE PROBLEM - 
                                    First Missing Positive (Hard)

        Given an unsorted integer array nums, find the smallest missing positive integer.

        You must implement an algorithm that runs in O(n) time and uses constant extra space.

link: https://leetcode.com/problems/first-missing-positive/

THIS IS A VERY SIMPLE SOLUTION USING C++ working with all test cases

*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        int ptr = 0;
 
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                ptr = 1;
                break;
            }
        }

        if (ptr == 0){
            return 1;
        }

        for (int i = 0; i < n; i++){
            if (nums[i] <= 0 || nums[i] > n){
                nums[i] = 1;
            }
        }
            

        for (int i = 0; i < n; i++){
            nums[(nums[i] - 1) % n] += n;   
        }
            
        for (int i = 0; i < n; i++){
            if (nums[i] <= n){
                return i + 1;
            }
        }
            
        return n + 1;
    }
};