/* QUESTION LINK: https://leetcode.com/problems/find-the-duplicate-number*/

//GIVEN:Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.


//There is only one repeated number in nums, return this repeated number.

/*
Example 1:

Input: nums = [1,3,4,2,2]
Output: 2

*/
#include<iostream>
using namespace std;
    int findDuplicate(vector<int>& nums) {
        int t,h;
        t=nums[0];//storing 0th index
        h=nums[0];//storing 0th index
        do{
            t=nums[t];
            h=nums[nums[h]];
        }while(h!=t);
        t=nums[0];
        while(h!=t)//when h==t we will get the sol
        {
            t=nums[t];
            h=nums[h];
        }
        return h;
    }  
// Driver Code
int main()
{
    int arr[] = { 1, 2, 3, 1 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    vector<int> nums;
    for(int i=0;i<arr_size;i++)
    {
        nums.push_back(arr[i]);
    }
    int ans=findDuplicate( nums);
    cout<<ans;
   return 0;
}
 
    
