// Intro:
// Problem link: https://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1#
// Given an array arr of n elements which is first increasing and then may be decreasing, find the maximum element in the array.
// Note: If the array is increasing then just print then last element will be the maximum value.
// A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.
// Iterate through the array and find the largest number.


// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) 
	{
	    int c=0,max=0;
	    for(int i=0;i<(n-1);i++)
	    {
	        if(arr[i]<arr[i+1])
	        {
	            max=arr[i+1];
	            c++;
	        }
	    }
	    return max;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// Sample input/output

// Example 1:
// Input: 
// n = 9
// arr[] = {1,15,25,45,42,21,17,12,11}
// Output: 45
// Explanation: Maximum element is 45.

// Example 2:
// Input: 
// n = 5
// arr[] = {1, 45, 47, 50, 5}
// Output: 50
// Explanation: Maximum element is 50.


// Time complexity: O(n). 
// One traversal is needed so the time complexity is O(n)
// Space Complexity: O(1). 
// No extra space is needed, so space complexity is constant