//-------Two Sum Problem-------//

// Problem Link: https://leetcode.com/problems/two-sum/

/*
Problem Statement: Given an array of integers nums and an integer target, return indices 
of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the 
same element twice.

You can return the answer in any order.
*/

/* 
Logic:
A simple implementation uses two iterations. In the first iteration, we add each element's value 
and its index to the hash table. Then, in the second iteration we check if each element's complement 
(target - nums[i]) exists in the table. Beware that the complement must not be nums[i] itself! 
*/

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map <int,int> mp;
        vector <int> v;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        int ans=0,in=-1;
        
        for(int i=0;i<nums.size();i++)
        {   
            in=i;
            auto it1=mp.find(nums[i]);
            int x=target-nums[i];
            auto it=mp.find(x);
            
            if(it!=mp.end())
            {   
                if(it==it1)
               {
                  if(it->second>1)
                  {
                     ans=x;
                     v.push_back(i);
                     break; 
                  }
               }
               
               else{
                ans=x;
                v.push_back(i);
                break;
               }
            }
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(ans==nums[i] && in!=i)
            {
                v.push_back(i);
            }
        }
       
        return v;
    }
};