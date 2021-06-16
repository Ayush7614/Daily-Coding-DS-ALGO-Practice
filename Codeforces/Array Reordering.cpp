#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll gcd(ll a, ll b)
{
	if(a==0)
	    return b;
	if(b==0)
	    return a;
	if(a==b)
	    return a;
	if(a>b)
	    return gcd(a-b, b);
	return gcd(a, b-a);
}

int main()
{
    fastio();
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
		cin>>n;
		ll arr[n], copy[n];
		ll j=0, k=n-1;
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
			if(arr[i]%2==0)
			    copy[j++] = arr[i];
			else 
			    copy[k--] = arr[i];
		}
		ll ans = 0;
		for(ll i=0;i<n;i++)
		 {
			if(copy[i]%2==0)
			    ans += n-1-i;
			else
			{
				for(ll j=(i+1);j<n;j++)
				{
					ll temp = gcd(copy[i], 2*copy[j]);
					if(temp>1)
					    ans++;
				}
			}
		}
		cout<<ans<<endl;
        
    }
    
    
    return 0;
}