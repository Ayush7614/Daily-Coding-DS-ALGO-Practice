#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends




int maxLen(int A[], int n)
{
  //taken map
    unordered_map<int,int>mp;
  //initialising sum and max to 0
    int sum=0;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
      //normal we will add the sum of numbers
        sum=sum+A[i];
      //if 0 than increment the maxi
        if(sum==0)
        {
            maxi=i+1;
        }
        else
        {
          //else find in the map 
            if(mp.find(sum)!=mp.end())
            {
              //if we find than we have to comapre that from which one maximum is there from maxi or from the element sored in the map
                maxi=max(maxi,i-mp[sum]);
            }
            else
            {
              //else we have to just assign the index to the map 
                mp[sum]=i;
            }
        }
    }
  //return the maxi 
    return maxi;
    
    
}

// Test Case

// Example 1:

// Input:
// N = 8
// A[] = {15,-2,2,-8,1,7,10,23}
// Output: 5
// Explanation: The largest subarray with
// sum 0 will be -2 2 -8 1 7.
