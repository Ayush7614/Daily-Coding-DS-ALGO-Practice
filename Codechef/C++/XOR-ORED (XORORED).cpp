#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n,mx=0,indx=0,ans=-1;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    ans=a[0];
    for(int i=0;i<n;i++)
    ans=ans&a[i];
    for(int i=0;i<n;i++)
    mx=mx|(a[i]^ans);
    cout<<ans<<" "<<mx<<"\n";
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