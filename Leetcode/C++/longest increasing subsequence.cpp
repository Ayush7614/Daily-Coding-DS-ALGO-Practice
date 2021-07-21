//Link to the problem
/*
  https://leetcode.com/problems/longest-increasing-subsequence/
 */

//According to the problem:

//Given an integer array nums, 
//NOTE:A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements.
//AIM: Return the length of the longest strictly increasing subsequence.

/*
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/
class Solution {
public:
   
  int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        int lis[n];
        memset(lis, 0, sizeof(lis));//initializing array to 0
        int max_1 = INT_MIN;
        for(int i = 0; i < n; i++){
            if(i == 0)//base case
                lis[i] = 1;
            else{
                for(int j = 0; j < i; j++){
                    if(nums[j] < nums[i])
                        lis[i] = max(lis[i], lis[j] + 1);
                    else
                        lis[i] = max(lis[i], 1);    
                }
            }
            max_1 = max(max_1, lis[i]);//checking for max length
        }
        return max_1;
        
    }
};