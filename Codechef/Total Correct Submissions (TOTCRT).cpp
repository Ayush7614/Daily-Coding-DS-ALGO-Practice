#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    map<string,int> mp;
    string s;
    int n,x;
    cin>>n;
    for(int i=0;i<3*n;i++)
    {
        cin>>s>>x;
        mp[s]+=x;
    }
    vector<int> ans;
    map<string,int>::iterator itr;
    for (itr = mp.begin(); itr != mp.end(); ++itr) 
    ans.push_back(itr->second);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    cout<<"\n";
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