#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n >>k;
	    if(k==0)
	    cout<<n<<endl;
	    else
	    cout<<n%k<<endl;
	}
	return 0;
}
