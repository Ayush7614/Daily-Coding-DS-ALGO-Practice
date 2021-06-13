#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl "\n"
#define mod 1000000007
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
    // Write your code here
    ll n;
    cin>>n;
    ll a[n+1][n+1] = {0};
    fo(i,0,n)
    {
        cin>>a[i+1][i+1];
    }
    for(i=1; i<=n; i++)
    {
        flag = 0;
        ll c = a[i][i]-1;
        ll k = i, j = i;
        for(ll h = 1; h<=c; h++)
        {
            if(j-1>=1 && a[k][j-1]==0)
                a[k][--j]=a[i][i];
            else
                a[++k][j]=a[i][i];
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[i][j]==0)
                break;
            else
                cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
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