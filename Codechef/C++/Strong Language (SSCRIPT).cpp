#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k,counter=0;
	    string s;
	    cin>>n>>k>>s;
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]=='*')
	        counter++;
	        else if(counter==k)
	        break;
	        else
	        counter=0;
	    }
	    (counter==k)?cout<<"YES"<<endl:cout<<"NO"<<endl;
	}
	return 0;
}