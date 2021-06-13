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
    ll n, mx = INT_MIN, mn = INT_MAX;
    ll y = 0, z = 0;
    cin>>n;
    vec v(n);
    fo(i,0,n)
    {
        cin>>v[i];
        if(v[i]>mx)
        {
            mx = v[i];
            y = i+1;
        }
        if(v[i]<mn)
        {
            mn=v[i];
            z = i+1;
        }
    }
    ll p = min(y,z), q = y+z-p;
    ll r = min(n-p+1,p+n-q+1);
    cout<<min(q,r)<<endl;
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