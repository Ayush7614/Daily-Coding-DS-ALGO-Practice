#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,ans=1;
        cin>>n;
        for(ll i=1;i<=n;i++)
        ans*=i;
        cout<<ans<<'\n';
        
        
        
        
    }
    
    
    
    return 0;
}