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

// Sample Input/Output


// Example Input
// 3
// 1
// A 1
// B 2
// C 3
// 2
// AA 1
// AB 1
// AB 1
// AC 1
// AC 1
// AD 1
// 1
// Z 100
// Z 100
// Z 100


// Example Output
// 1 2 3
// 1 1 2 2
// 300