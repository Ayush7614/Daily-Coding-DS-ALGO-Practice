/*
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
  
Input:
N = 3 
A[] = {1,2,3} 
Output:
-1
Explanation:
Since, each element in 
{1,2,3} appears only once so there 
is no majority element.

*/

#include<bits/stdc++.h>
using namespace std;


class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        int max = 0;
        int idx = 0;
        int fin = size/2;
        map<int,int>mp;
        for(int i=0; i<size; i++)
        {
            mp[a[i]]++;
        }
        for(auto it : mp)
        {
            if(it.second>max)
            {
                idx = it.first;
                max = it.second;
            }
        }
        
     
        return max>fin?idx : -1;
        
    }
};

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
