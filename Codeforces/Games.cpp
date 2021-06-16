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
    ll n;
    cin>>n;
    vector<pair<int,int>> v;
    loop(i,0,n)
    {
        ll x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    
    ll count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            
            if(v[i].first==v[j].second)
                count++;
            if(v[i].second==v[j].first)
                count++;
        }
    }
    cout<<count/2<<endl;
    
    
    return 0;
}