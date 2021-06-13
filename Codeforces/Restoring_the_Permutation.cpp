#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl "\n"
#define mod 10000007
#define vec vector <ll>
#define vecp vector <pair<ll,ll>>
#define mp make_pair
#define A first
#define B second
#define all(v) v.begin(),v.end()
#define mpl map<ll,ll>
#define umpl unordered_map<ll,ll>
#define fo(i,a,b) for(i=a; i<b; i++)
using namespace std;

void solve()
{
    ll i,j,flag = 0;
    //Write your Code here
    ll n;
    cin>>n;
    vec a(n);
    bool vis[n+1]={false};
    fo(i,0,n){
        cin>>a[i];
    }
    vec f,small(n,-1), large(n,-1);
    small[0]=large[0]=a[0];
    vis[a[0]]=1;
    for(i=1; i<n; i++)
    {
        if(a[i]>a[i-1])
        {
            small[i]=a[i];
            large[i]=a[i];
            vis[a[i]]=1;
        }
    }
    for(i=1; i<=n; i++)
    {
        if(!vis[i])
            f.pb(i);
    }
    // for small
    j = 1;
    for(i=0; i<n; i++)
    {
        if(small[i]!=-1)
            cout<<small[i]<<" ";
        else{
            while(vis[j])
                j++;
            cout<<j<<" ";
            vis[j++]=true;
        }
    }
    cout<<endl;
    //for large
    for(i=0; i<n; i++)
    {
        if(large[i]!=-1)
            cout<<large[i]<<" ";
        else
        {
            auto k = lower_bound(all(f),a[i]);
            k--;
            cout<<f[k-f.begin()]<<" ";
            f.erase(k);
        }
    }
    cout<<endl;
}
 
int main()  
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t=1;
    cin>>t;
    for(int i= 1; i<=t; i++)
    {
        solve();
    }
    return 0;
}

