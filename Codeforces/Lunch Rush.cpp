#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    fastio();
    
    ll n,k;
    cin>>n>>k;
    ll ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        ll f,t;
        cin>>f>>t;
        if(t<=k)
        {
            if(f>=ans)
                ans=f;
        }
        else
        {
            if(f-(t-k)>ans)
                ans=(f-(t-k));    
        }
        
    }
    
    cout<<ans<<endl;
    
    
    
    return 0;
}