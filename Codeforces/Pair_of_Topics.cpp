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
    vec a(n),b(n);
    vec f,v;
    fo(i,0,n)
        cin>>a[i];
    fo(i,0,n){
        cin>>b[i];
        f.pb(a[i]-b[i]);
    }
    sort(all(f));
    ll ans = 0, k = -1;
    fo(i,0,n)
    {
        if(f[i]<=0)
            continue;
        ll k = upper_bound(all(f),-1*f[i])-f.begin();
        ans+=(i-k);
    }
    cout<<ans<<endl;
}
 
int main()  
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t=1;
    //cin>>t;
    for(int i= 1; i<=t; i++)
    {
        solve();
    }
    return 0;
}
