/* QUESTION LINK: https://leetcode.com/problems/total-hamming-distance/*/

//GIVEN:Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.
//EXAMPLE:
/*
Example 1:

Input: nums = [4,14,2]
Output: 6
Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case).
The answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.*/


//EXPLAINATION:
/*Let say for i= 0 , number of elements having set bit is c
So. this set bit will generate total hamming distance (nums.size()-c) * c.

Like if array given {1,2,3,4,5}={ 001 , 010 , 011 , 100 , 101 }
so at 0th index, number of elements having set bit at 0th index is 3
And 2 elements having unset at 0th index.
So total hamming distace for i=0 will be 3 * 2=6
Same we can go for i=1,2,3,...31 and add all the distance and return final distance
*/

include<iostream>
using namespace std;

    int totalHammingDistance(vector<int>& nums) {
        int res=0;
        for(int i=0;i<32;i++)
        {
            int c=0;
            for(int j=0;j<nums.size();j++)
            {
                if((1<<i)&nums[j]) c++;  //checking ith bit set or not
            }
            res+=(nums.size()-c)*c;
        }
        return res;
        
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
    int ans= totalHammingDistance(nums);
    cout<<ans;
   return 0;
}
 
    
