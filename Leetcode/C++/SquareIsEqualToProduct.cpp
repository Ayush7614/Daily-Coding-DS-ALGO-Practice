// Number of Ways Where Square of Number Is Equal to Product of Two Numbers
// Link to the Problem - https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/

// Problem Statement -
/*
Given two arrays of integers nums1 and nums2, return the number of triplets formed (type 1 and type 2) under the following rules:

Type 1: Triplet (i, j, k) if nums1[i]2 == nums2[j] * nums2[k] where 0 <= i < nums1.length and 0 <= j < k < nums2.length.
Type 2: Triplet (i, j, k) if nums2[i]2 == nums1[j] * nums1[k] where 0 <= i < nums2.length and 0 <= j < k < nums1.length.
 
Example 1:
Input: nums1 = [7,4], nums2 = [5,2,8,9]
Output: 1
Explanation: Type 1: (1,1,2), nums1[1]^2 = nums2[1] * nums2[2]. (4^2 = 2 * 8). 

Example 2:
Input: nums1 = [1,1], nums2 = [1,1,1]
Output: 9
Explanation: All Triplets are valid, because 1^2 = 1 * 1.
Type 1: (0,0,1), (0,0,2), (0,1,2), (1,0,1), (1,0,2), (1,1,2).  nums1[i]^2 = nums2[j] * nums2[k].
Type 2: (0,0,1), (1,0,1), (2,0,1). nums2[i]^2 = nums1[j] * nums1[k].
*/


// Solution to the Problem
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        // Result of the Function
        int resultOfTriplet = 0;

        // Count Type 1
        for(unsigned int i=0; i < nums1.size(); i++){
            for(unsigned int j=0; j < nums2.size(); j++){
                for(unsigned int k=j+1; k < nums2.size(); k++){
                    if((nums1[i]*nums1[i]) == nums2[j]*nums2[k]){
                        resultOfTriplet++;
                    }
                }
            }
        }

        // Count Type 2
        for(int i=0; i < nums2.size(); i++){
            for(int j=0; j < nums1.size(); j++){
                for(int k=j+1; k < nums1.size(); k++){
                    if((nums2[i]*nums2[i]) == nums1[j]*nums1[k]){
                        resultOfTriplet++;
                    }
                }
            }
        }

        // Return Result
        return resultOfTriplet;
    }
};

// Main
int main()
{
    int nums1[1000], nums2[1000];
    cout<<"Enter Elements for nums1[] :- ";
    cin>>nums1[];

    cout<<"Enter Elements for nums2[] :- ";
    cin>>nums2[];

    Solution *ob;
    ob->numTriplets(nums1, nums2);
}


// Test Cases
/*
Example 1:
Input: nums1 = [7,7,8,3], nums2 = [1,2,9,7]
Output: 2

Example 2:
Input: nums1 = [4,7,9,11,23], nums2 = [3,5,1024,12,18]
Output: 0
*/
