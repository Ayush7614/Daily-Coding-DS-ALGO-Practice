#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll int n,k;
    cin>>n>>k;
    ll int a[n];
    for(ll int i=0;i<n;i++)
    cin>>a[i];
    vector<ll int> index(32,0);
    ll int temp,j;
    for(ll int i=0;i<n;i++)
    {
        j=0; 
        while(a[i]>0)
        {
            index[j]+=a[i]%2;
            a[i]>>=1;
            j++;    
        }
    }
    ll int ans=0;
    for(int i=0;i<index.size();i++)
    {
        if(index[i]%k==0)
        ans = ans + index[i]/k;
        else
        ans = ans + index[i]/k + 1;
    }  
    cout<<ans<<"\n";
}
int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

