#include <iostream>
using namespace std;

int main() {
	int t,k;
	cin>>t; // scanning number of testcases.
	while(t--)
	{
	    cin>>k; //scanning inputs
	    for(int i=1;i<=k;i++)
	    {
	        for(int j=0;j<k;j++)
	        {
	            if((i+j)>=k)
	                 cout<<"(";
	            else
	                 cout<<" ";
	        }
	        cout<<"*";
	        for(int j=1;j<=i;j++)
	        {
	            cout<<")";
	        }
	        cout<<endl;
	    }
	}
	return 0;
}
