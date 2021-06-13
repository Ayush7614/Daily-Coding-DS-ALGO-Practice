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
    ll a[n],sum = 0;
    fo(i,0,n)
    {
        cin>>a[i];
        sum+=a[i];
    }
    ll p = sum%n, q = sum/n;
    if(p!=0)
        cout<<"-1\n";
    else
    {
        ll k = 0;
        fo(i,0,n)
        {
            if(a[i]>q)
                k++;
        }
        cout<<k<<endl;
    }
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