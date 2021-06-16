#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unordered_set<int> s;
    for(int i=0;i<4;i++)
    {
        ll a;
        cin>>a;
        s.insert(a);
    }
    ll ans=s.size();
    cout<<abs(ans-4)<<endl;
    
    
    
    return 0;
}