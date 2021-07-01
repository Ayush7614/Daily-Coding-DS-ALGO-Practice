//Problem Link 
//https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxAns=0,c=1;
      //first do sort
         sort(nums.begin(),nums.end());
      //increment the loop from 1 and do it till we get nums[i]-nums[i-1]==1
      //and increment the count 
      //meanwhile create maxans to compare the maximum count 
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]==1)
            {
                c++;
            }
            else if(nums[i]-nums[i-1]==0)
            {
              maxAns=  max(maxAns,c);
                continue;
            }
            else
            {
                c=0;
            }
            maxAns = max(maxAns,c);

        }
      //return the maximum count
         return maxAns;
    }
};
//testcases
// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
