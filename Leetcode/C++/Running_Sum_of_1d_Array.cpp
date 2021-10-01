//Problem: https://leetcode.com/problems/running-sum-of-1d-array/

//Solution:

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>new;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            new.push_back(sum);
        }
        return new;
    }
};


//Test Case:
//Input: nums = [1,2,3,4]
//Output: [1,3,6,10]
//Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4]