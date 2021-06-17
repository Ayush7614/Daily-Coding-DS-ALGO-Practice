#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            ans[i] = ans[i-1] + nums[i];
        return ans;
    }
};