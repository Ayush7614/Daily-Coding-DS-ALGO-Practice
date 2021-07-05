// Problem Staement

/* 
Given a binary array, find the maximum number of consecutive 1's, by
flipping at most k 0's
*/

//Example Test Case 1

/*
Input: nums = [1,0, 1, 0, 1], k = 1
Output: 3

Explanation: We can flip either the 0 at the first index or at the 3rd index
[Considering 0- based indexing], which will give 3 consecutive 1's. We cannot
achieve more than 3 consecutive 1's as k is 1.
*/

//Example Test Case 2

/*
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6

Explanation: We can flip two 0's in either of the following ways
1>  Flipping 0's at index 4 and 5.
2>  Flipping 0's at index 5 and 10.
[Considering 0- based indexing], either of them will give 6 consecutive 1's. We
cannot acheive more than 6 consecutive 1's as k is 2.
*/


// Code goes as follows

//Header File which comprises all header files of C++.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>&nums, int k) {
        //Initialising maxConsecutiveOnes and zeroCount to 0

        int maxConsecutiveOnes=0;
        int zeroCount=0;

        //We are using a sliding window approach where pointers are start and
        //end. Intially both are pointing to 0 index i.e 1st element of the
        //vector.
        
        int start=0;
        int end;

        //Iterating over the size of vector
        for(end=0; end<nums.size(); end++)
        {

            //If condition to check whether the value at the given index is 0 or
            //not. If it is zero, increment the zeroCount

            if(nums[end]==0)
                zeroCount++;

            // A while loop to check whether the zeroCount has excedded k or
            // not. If so, move the start pointer of sliding window by 1 and
            // decrement zeroCount.

            while(zeroCount>k)
            {
                if(nums[start]==0)
                    zeroCount--;
                start++;
            }

            //storing the maximum number of Consecutive 1's 
            
            maxConsecutiveOnes=max(maxConsecutiveOnes, end-start+1);
        }   
        return maxConsecutiveOnes;
    }
};

int main()
{
    vector<int> nums;
    int size,k, ans;
    cin>>size;
    for(int i=0; i<size; i++)
    {
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    cin>>k;    
    Solution s;
    ans=s.longestOnes(nums, k);
    cout<<ans<<endl;
    return 0;

}