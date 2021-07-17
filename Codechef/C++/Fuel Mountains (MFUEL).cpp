#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	   int n;
	   cin>>n;
	   int arr[n];
	   for(int i=0;i<n;i++)
	   {
	       cin>>arr[i];
	   }
	   int sum=0, maxSum=INT_MIN;
	   for(int i=0;i<n;i++)
	   {
	       sum +=arr[i];
	       sum =max(sum , arr[i]);
	       maxSum= max(maxSum , sum);
	   }
	   cout<<maxSum<<endl;
	    
	}
	return 0;
}
