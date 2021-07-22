/* QUESTION LINK: https://leetcode.com/problems/find-the-duplicate-number*/

//GIVEN:Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.


//There is only one repeated number in nums, return this repeated number.

/*
Example 1:

Input: nums = [1,3,4,2,2]
Output: 2

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int t,h;
        t=nums[0];
        h=nums[0];
        do{
            t=nums[t];
            h=nums[nums[h]];
        }while(h!=t);
        t=nums[0];
        while(h!=t)
        {
            t=nums[t];
            h=nums[h];
        }
        return h;
    }
};