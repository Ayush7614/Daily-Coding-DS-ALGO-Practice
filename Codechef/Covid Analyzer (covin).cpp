#include <bits/stdc++.h> 
using namespace std;

int main() {
	 long long int t,n,ar[91];
    //scanning number of testcases
	cin>>t;
	while(t--)
	{
        //scanning input
	    cin>>n;
	    ar[0]=1;ar[1]=2;
	    for(int i=0;i<n;i++)
	    {
	        ar[i+2]=ar[i]+ar[i+1];
	       // cout<<ar[i+2]<<endl;
	    }
	    cout<<ar[n-1]<<endl;
	}
	return 0;
}
