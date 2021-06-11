#include <iostream>
using namespace std;

int main() {
	 long long int t,n,ar[91];
	cin>>t;//tescases scanning
	while(t--)
	{
	    cin>>n; // number of inputs
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
