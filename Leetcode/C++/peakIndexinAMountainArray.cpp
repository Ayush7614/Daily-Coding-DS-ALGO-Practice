/*
Problem Statement

Let's call an array arr a mountain if the following properties hold:

-> arr.length >= 3
-> There exists some i with 0 < i < arr.length - 1 such that:
    arr[0] < arr[1] < ... arr[i-1] < arr[i]
    arr[i] > arr[i+1] > ... > arr[arr.length - 1]
Given an integer array arr that is guaranteed to be a mountain, return any i such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

Input: arr = [0,1,0]
Output: 1

Constraints:
3 <= arr.length <= 104
0 <= arr[i] <= 106
arr is guaranteed to be a mountain array.

*/

/*
Time Complexity: O(log(N))
Space Complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) 
    {
        int l=0;
        int u=arr.size()-1;
        int n=arr.size();
        while(l<=u)
        {
            int m=(l+u)/2;
            int prev=(m-1+n)%n;
            int next=(m+1)%n;
            if(arr[m]>arr[prev]&&arr[m]>arr[next])
                return m;
            else if(arr[m]>arr[prev]&&arr[m]<arr[next])
                l=next;
            else if(arr[m]>arr[next]&&arr[m]<arr[prev])
                u=prev;
        }
        return -1;
    }

int main()
{
    vector<int> arr={0,1,0};
    int ans=peakIndexInMountainArray(arr);
    cout<<ans<<" ";
    return 0;
}

