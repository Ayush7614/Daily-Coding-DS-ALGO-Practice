#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n,sum=0;
	    cin>>n;
	    while(n>0)
	    {
	        int x=n%10;
	        sum+=x;
	        n=n/10;
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
