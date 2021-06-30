#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    cout<<(2*(180+n)-(a+b))<<"\n";
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