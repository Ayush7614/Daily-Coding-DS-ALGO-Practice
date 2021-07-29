#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll int e,k,a=0;
    cin>>e>>k;
    while(e>0)
    {
        e=e/k;
        a++;
    }
    cout<<a<<"\n";
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