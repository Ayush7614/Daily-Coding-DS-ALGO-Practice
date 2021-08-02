#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n,tmp,ans=0;
    cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        mp[tmp]++;
    }
    for(auto i:mp)
    {
        ans+=min((i.first-1),i.second);
        //cout<<(i.first-1)<<" "<<i.second<<endl;
    }
    cout<<ans<<"\n";
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