#include <iostream>
using namespace std;

int main() {
	int t,k;
    //Read the number of testcases
	cin>>t;
	while(t--)
	{
	    cin>>k;
	    for(int i=1;i<=k;i++)
	    {
	        for(int j=1;j<=k;j++)
	        {
	            if(i>=j)
	                cout<<j;
	            else
	                cout<<"*";
	        }
	        cout<<endl;
	    }
	}
	return 0;
}
