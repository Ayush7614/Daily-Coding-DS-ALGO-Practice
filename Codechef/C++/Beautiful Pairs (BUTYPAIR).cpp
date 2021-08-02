#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n,c=0,d=0,p;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++)
    {
        auto it = lower_bound(a.begin()+i+1,a.end(),a[i]+1);
        p = it-a.begin();
        c+=(n-p);
    }
    cout<<c*2<<"\n";
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