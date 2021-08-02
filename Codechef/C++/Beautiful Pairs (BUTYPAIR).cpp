// Problem link: https://www.codechef.com/LTIME98C/problems/BUTYPAIR
// The equation (Ai−Aj)/Ai < (Ai−Aj)/Aj can be changed into 
// 1 - Aj/Ai < Ai/Aj - 1
// 2 < Ai/Aj + Aj/Ai
// 2 < (Ai^2 + Aj^2)/AiAj
// 2AiAj < (Ai^2 + Aj^2)
// (Ai-Aj)^2 > 0
// Therefore the pairs are beautiful as long as Ai != Aj
// Maintain a frequency array to find out the duplicate element
// ans += (n-freq)*freq

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll int n,d=0,p;
    cin>>n;
    map<ll int,ll int> mp;
    for(ll int i=0;i<n;i++)
    {
        cin>>p;
        mp[p]++;
    }
    for(auto i:mp)
    d+=(n-i.second)*i.second;
    cout<<d<<"\n";
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

// Sample input/output

// Sample Input 1 
// 2
// 3
// 4 2 4
// 6
// 2 8 6 2 1 5

// Sample Output 1 
// 4
// 28