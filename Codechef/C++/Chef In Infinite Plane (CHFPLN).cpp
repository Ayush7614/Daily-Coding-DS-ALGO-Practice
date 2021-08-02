// Problem link: https://www.codechef.com/COOK131C/problems/CHFPLN
// The maximum way in which a number can be split is (n-1) ways
// For example 4 can be split into (1,3), (2,2), (3,1). If 4 exist more than 3 times then the pattern will be repeated
// In this question we have to find the frequency of occurance of number and the number of ways it can be split, the minimum of two will be considered

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
        cin>>tmp;           // to find frequency of a number we have used frequency array
        mp[tmp]++;
    }
    for(auto i:mp)
    ans+=min((i.first-1),i.second);     // Consider minimum of both of them
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

// Sample input/output 

// Sample Input 1 
// 2
// 6
// 2 2 4 4 2 6 
// 2
// 16 8

// Sample Output 1 
// 4
// 2