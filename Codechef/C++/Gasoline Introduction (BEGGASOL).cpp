#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>> arr[i];
	    int dist=0;
	    int fuel=arr[0];
	    for(int i=1;i<n && fuel>0;i++)
	    {
	        fuel--;
	        fuel +=arr[i];
	        dist++;
	    }
	    cout<<(dist + fuel)<<endl;
	}
	return 0;
}
