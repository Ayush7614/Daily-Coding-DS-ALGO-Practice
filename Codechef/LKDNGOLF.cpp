#include <iostream>
using namespace std;

int main() {
	// your code goes here
		long long T;
	cin>>T;
	for(int i=1; i<=T; i++)
	{
	    long long N,x,k;
	    cin>>N>>x>>k;
	    if (x%k==0 || (N+1-x)%k==0)
	    cout<<"YES"<<endl;
	    else
	     cout<<"NO"<<endl;
	}
	return 0;
}
