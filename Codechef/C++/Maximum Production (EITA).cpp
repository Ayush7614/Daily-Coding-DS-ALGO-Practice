#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int d,x,y,z;
    cin>>d>>x>>y>>z;
    cout<<max(x*7,(y*d)+(7-d)*z)<<"\n";
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