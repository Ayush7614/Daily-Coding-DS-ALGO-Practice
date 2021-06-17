#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long t;
	cin>>t;
	while(t--!=0)
	{
	    long long d,D,P,Q,sum=0;
	    cin>>D>>d>>P>>Q;
	    long long k=D/d;
	     if(D%d==0)
	     {
	         sum+=d*(P*k+(k*(k-1)/2)*Q);
	     }
	     else
	     {
	         sum+=d*(P*k+(k*(k-1)/2)*Q);
	        // cout<<sum;
	         sum+=(D%d)*(P+(k*Q));
	     }
	    cout<<sum<<"\n";
	    
	}
	return 0;
}
