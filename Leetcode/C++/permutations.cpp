/*                                          LEETCODE PROBLEM - #46 (MEDIUM)
                                                    Permutations

Link to Problem: https://leetcode.com/problems/permutations/

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]
*/

class Solution {
public:
    
    void calculate (int index,vector<int>& nums,vector<vector<int>> &ans){
      if(index == nums.size())
      {
         ans.push_back(nums);
          return ;
      }
        
      for(int i=index;i<nums.size();i++)
      {
          swap(nums[index],nums[i]);
          calculate(index+1,nums,ans);
          swap(nums[index],nums[i]);
      }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        calculate(0,nums,ans);
        return ans;
    }
};

/*
In this code we create a new function named calculate which will play a major role 
to perform our recursion task.


26 / 26 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 7.6 MB

TIME COMPLEXITY: O(N)

*/