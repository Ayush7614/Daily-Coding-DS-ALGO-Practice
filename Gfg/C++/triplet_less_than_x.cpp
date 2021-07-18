Given an array arr[] of distinct integers of size N and a sum value X, the task is to find count of triplets with the sum smaller than the given sum value X.

Input: N = 4, X = 2
arr[] = {-2, 0, 1, 3}
Output:  2
Explanation: Below are triplets with 
sum less than 2 (-2, 0, 1) and (-2, 0, 3)


#include <bits/stdc++.h>
using namespace std;

class Solution
{	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr,arr+n);
	    int ans = 0;
	    
	    for(int i=0; i<n-2; i++)
	    {
	        int j=i+1;
	        int r = n-1;
	        while(j<r)
	        {
	            if(arr[i]+arr[j]+arr[r]>=sum)
	            {
	                r--;
	            }
	            else
	            {
	                ans+=(r-j);
	                j++;
	            }  
	        }
	    }
	    return ans;
	}
};

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}
