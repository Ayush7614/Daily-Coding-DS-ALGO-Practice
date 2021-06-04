#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    
	    ll n,e,c,po,pm,pk;
	    cin>>n>>e>>c>>po>>pm>>pk;
	    vector<ll> sol;
	    vector<ll> k;
	    for(int i=0;i<=n+1;i++)
	    {
	        k.push_back(i);
	    }
	    for(ll m=0;m<=n;m++)
	    {
	        ll x1 = lower_bound(k.begin(),k.end(),(2*n-e-2*m))-k.begin();
	        ll x2=upper_bound(k.begin(),k.end(),(c-3*m))-k.begin()-1;
	        if(x2<x1  || x1==n+1)
	        {
	            continue;
	        }
	        if(x2==n+1 && x2+3*m>c)
	        continue;
	        ll kk;
	        if(pk>po)
	        kk=(x1<(n-m)?x1:(n-m));
	        else
	        kk=(x2<(n-m)?x2:(n-m));
	        ll o=n-kk-m;
	        if(kk+2*m>=2*n-e && kk+3*m<=c)
	            sol.push_back(po*o+pm*m+pk*kk);
	            
	    }
	    if(sol.size()==0)
	        cout<<"-1"<<endl;
	    else
	    {
	        ll min=sol[0];
	        for(ll i=0;i<sol.size();i++)
	        {
	            if(sol[i]<min)
	            min=sol[i];
	            
	        }
	        cout<<min<<endl;
	    }
	    
	}
	return 0;
}
