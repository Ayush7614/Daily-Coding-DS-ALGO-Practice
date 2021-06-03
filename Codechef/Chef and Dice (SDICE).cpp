#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll sum=0;
	    sum = (n/4)*44;
	    ll rem =n%4;
	    if(n>=4)
	    {
	        if(rem==0)
	        sum +=16;
	        else if(rem==1)
	        sum+=32;
	        else if(rem==2)
	        sum+=44;
	        else if(rem==3)
	        sum+=55;
	        cout<<sum<<endl;
	    }
	    else
	    {
	        ll res;
	        if(rem==1)
	        res=20;
	        else if(rem==2)
	        res=36;
	        else if(rem==3)
	        res=51;
	        cout<<res<<endl;
	    }
	    
	    
	}
	return 0;
}
